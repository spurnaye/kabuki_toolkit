/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/tek/tek_flowcontroller.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include "c_flowcontroller.h"

namespace _ {

UI4 ConvertGallonsToMilliiters(FP4 Value) { return (UI4)(Value * 3785.41f); }

FP4 ConvertMilliitersToGallons(UI4 Value) { return (3785.41f / (FP4)Value); }

FlowController::FlowController(PinName sensor_pin, PinName solenoid_pin,
                               PinName pot_pin, UI4 max_flow_ml)
    : sensor_(sensor_pin),
      valve_(solenoid_pin),
      pot_(pot_pin),
      count_(0),
      flow_rate_ml_(0),
      total_flow_ml_(0),
      target_flow_ml_(max_flow_ml / 2),
      max_flow_ml_(max_flow_ml) {
  UI2 temp = pot_.read_u16();
  last_sample_ = temp;
  sensor_.rise(callback(this, &FlowController::PulseFlowSensor));
}

void FlowController::StartWatering(SI4 index) {
  count_ = flow_rate_ml_ = total_flow_ml_ = 0;

  if (target_flow_ml_ == 0) return;

  OpenValve();

  PrintLine();
  Print(index);
}

void FlowController::Print(SI4 index) {
  cout << "\n| " << index << ": flow rate = " << flow_rate_ml_
       << " mL/s, total =  " << total_flow_ml_
       << " mL, target =  " << target_flow_ml_ << " mL";
}

void FlowController::UpdateTargetFlow() {
  UI2 sample = pot_.read_u16(), last_sample = last_sample_;

  last_sample_ = sample;

  if ((sample > last_sample - 300) && (sample < last_sample + 300)) return;

  UI4 tempTargetFlow_mL = (sample * max_flow_ml_) / 0xffff;

  target_flow_ml_ = tempTargetFlow_mL < 100 ? 0 : tempTargetFlow_mL;

  if (total_flow_ml_ >= tempTargetFlow_mL)
    CloseValve();
  else
    OpenValve();
}

inline void FlowController::StopWatering(SI4 Index) {
  CloseValve();
  Print(Index);
  cout << "\n| Done watering";
  PrintLine();
}

void FlowController::Update(SI4 Index) {
  UpdateTargetFlow();

  /// Update the flow sensor pulse count and flow calculations.

  UI4 tempFlowRate_mL = (2000 * count_) / 540;
  flow_rate_ml_ = tempFlowRate_mL;
  total_flow_ml_ += tempFlowRate_mL;

  if (total_flow_ml_ >= target_flow_ml_)
    StopWatering(Index);
  else
    Print(Index);
}

void FlowController::PulseFlowSensor() { ++count_; }

void FlowController::OpenValve() { valve_ = 1; }

void FlowController::CloseValve() { valve_ = 0; }

const Operation* FlowController::Star(char_t index, Expr* expr) {
  static const Operation This = {"FlowController", NumOperations(0),
                                 FirstOperation('a'), "tek", 0};

  switch (index) {
    case '?':
      return &This;
    case 'a':
      static const Operation Opa = {"Open", NumOperations(1),
                                    FirstOperation('a'), "Opens the valve.", 0};
      if (!expr) return &Opa;
      OpenValve();
      return NilResult();
  }
  return nullptr;
}

FlowControllerOp::FlowControllerOp(FlowController* flow_co)
    : flow_co_(flow_co) {}

const Operation* FlowControllerOp::Star(char_t index, Expr* expr) {
  return flow_co_->Star(index, expr);
}

}  // namespace _
