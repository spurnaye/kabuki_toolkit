/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/tek/tek_unicontroller.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include "c_unicontroller.h"

namespace _ {

Unicontroller::Unicontroller(UI1* mixer, ch_t num_channels, Led** leds,
                             ch_t num_leds, LEDRGB** rgb_leds,
                             ch_t num_rgb_leds, Button** buttons,
                             ch_t num_buttons, Pot** pots, ch_t num_pots,
                             RotaryKnob** knobs, ch_t num_knobs,
                             RotaryKnobBank** knob_banks, ch_t num_banks,
                             // PortIn        ** port_in   , ch_t num_ports_in,
                             IoExpander** extra_io, ch_t num_expanders)
    : brightness_(kDefaultLedBrightness),
      red_mix_(kDefaultLedBrightness),
      green_mix_(kDefaultLedBrightness),
      blue_mix_(kDefaultLedBrightness),
      pulse_count_(0),
      num_pulses_(0),
      spi_index_(0),
      channel_count_(num_channels),
      num_leds_(num_leds),
      num_rgb_leds_(num_rgb_leds),
      num_buttons_(num_buttons),
      num_pots_(num_pots),
      num_knobs_(num_knobs),
      num_knob_banks_(num_banks),
      // num_ports_in_   (num_ports_in),
      num_expanders_(num_expanders),
      leds_(leds),
      rgb_leds_(rgb_leds),
      knobs_(knobs),
      buttons_(buttons),
      pots_(pots),
      extra_io_(extra_io),
      // ports_in_       (ports_in),
      mixer_(mixer) {
  ch_t longest_chain = 0, i;
  UI1 temp;

  for (i = 0; i < num_expanders; ++i) {
    temp = extra_io_[i]->GetNumInBytes();
    if (temp > longest_chain) {
      longest_chain = temp;
    }
  }
  longest_chain_ = longest_chain;
}

RotaryKnob** Unicontroller::GetRotaryKnobs() { return knobs_; }

Pot** Unicontroller::GetPots() { return pots_; }

IoExpander** Unicontroller::GetIoExpanders() { return extra_io_; }

// PortIn** Unicontroller::GetPortsIn () {
//    return ports_in_;
//}

Led** Unicontroller::GetLeds() { return leds_; }

void Unicontroller::SetColorBalance(UI1 r, UI1 g, UI1 b) {
  red_mix_ = r;
  green_mix_ = g;
  blue_mix_ = b;
}

void Unicontroller::PollInputs() {
  // SI4 i;
  // UI2 value;

  // poll potentiometers.
  // value = pot_1_->read_u16 ();

  // SI4 time_us = timer_.read_us ();

  // CPU ALU divide rounds down so add 1 to aligned memory if needed.
  // ch_t num_words = (num_in_bytes_ & 3) ? 1 : 0;
  // num_words += num_in_bytes_ / sizeof (uintptr_t);

  // uintptr_t debounced_xor_[num_words];    //<

  // for (i = 0; i < num_words; ++i) {
  //    debounced_xor_[i] = debouncers_[i].Debounce (*((SI4)DigitalIns));
  //}

  // Debounce General Purpose Input (GPI) Ports.
  // for (; i < num_words + NumGPIPorts; ++i) {
  //    SI4 temp   = PortsIn[i - num_words],
  //        result = debouncers_[i - num_words].Debounce (temp);
  //    debounced_xor_[i] = result;
  //}

  // Debounce buttons.
  // for (i = 0; i < num_buttons_; ++i) {
  //    buttons_[i].Poll (this);
  //}

  // Debounce rotary Encoders.
  // SI4 time = timer_.read_us ();
  // for (i = 0; i < num_encoders_; ++i)
  //    rotary_knobs_[i].Poll (this, i, debounced_xor_, time);
}

inline void Unicontroller::UpdateLEDs() {
  SI2 count = pulse_count_;  //< local copy.
  pulse_count_ = (--count < 0) ? num_pulses_ - 1 : count;
  //< Increment counter or loop around.

  // for (SI4 i = numLEDs - 1; i >= 0; --i)
  //    lights_[i].Update ();

  // for (SI4 i = 0; i < num_led_ring_sets_; ++i) {
  //    //led_rings[i].Update (channels_, min_values_, max_values_,
  //                        count >> 8, count);
  //}
}

void Unicontroller::UpdateSpiByte() {
  // for (SI4 i = num_spi_ports_ - 1; i >= 0; --i)
  //    spi_ports_[i].Update (spi_index_);

  if (++spi_index_ < longest_chain_) return;

  spi_index_ = 0;
  PollInputs();
  UpdateLEDs();
}

SI4 Unicontroller::GetTimerCount() { return timer_.read_us(); }

}  // namespace _
