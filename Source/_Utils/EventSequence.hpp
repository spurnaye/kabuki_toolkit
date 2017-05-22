/** The Chinese Room
    @file    /.../Library/ChineseRoom\EventSequence.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright(C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved(R).

        Licensed under the Apache License, Version 2.0(the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

                    http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#pragma once

#include "Terminal.hpp"
#include "IEvent.hpp"

namespace _ {

class EventSequence;

class EventNode
/*< An IEvent node in a linear linked list. */
{
    public:
    
    EventNode(IEvent* nodeEvent);
    /*< Constructs an event node with the given IEvent. */

    EventNode* getNext();
    /*< Gets the next IEvent */
    
    IEvent* getEvent();
    /*< Gets the event this node triggers. */

    void setEvent(IEvent* newEvent);
    /*< Sets the event this node triggers. */

    void trigger(EventSequence* source);
    /*< Triggers the event. */

    void query(Terminal& io);
    /*< Prints this object to the terminal. */
    
    private:

    _Noncopyable_(EventNode)
    
    IEvent* iEvent;             //< The event this node triggers.
    EventNode* next;            //< The next node in the LLL.
};

class EventSequence : public _::IEvent
/** A sequence of events stored as a linear linked list. */
{
    public:
    
    EventSequence();
    /*< Constructs an empty event sequence. */

    void trigger();
    /*< Triggers the event. */

    void query(Terminal& io);
    /*< Prints this object to the terminal. */

    private:

    _Noncopyable_(EventSequence)

    EventNode* head;            //< Head of the linear linked list of IEventNode(s).
    timestamp_t eventTime;      //< The time in microseconds the event occurred.
};

}   //<  _