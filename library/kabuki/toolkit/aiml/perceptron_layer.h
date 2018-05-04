/** Kabuki Toolkit
    @version 0.x
    @file    ~/library/kabuki/toolkit/aiml/perceptron_layer.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2014-2017-2018 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <stdafx.h>

#if MAJOR_SEAM >= 5 && MINOR_SEAM >= 1

namespace kabuki { namespace toolkit { namespace aiml {

#include "perceptron.h"

/** A layer in a Multi-layer Perceptron Network.
    Each Perceptron is individually controlled, but it is convenient to 
*/
class PerceptronLayer {
    public:

    PerceptronLayer (uint32_t neuron_count, float_t bias);

    void Connect (PerceptronLayer* layer);

    void Disconnect (PerceptronLayer* layer);

    Perceptron* GetPerceptron (size_t index);

    void Update ();

    private:

    float_t                 bias_;        //< Layer bias value.
    std::vector<Perceptron> perceptrons_; //< Layer perceptrons.
    PerceptronLayer*        next_layer_;  //< Next layer in the list.
};

}   //< namespace aiml
}   //< namespace toolkit
}   //< namespace kabuki
#endif  //< #if MAJOR_SEAM >= 5 && MINOR_SEAM >= 1
