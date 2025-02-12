/*
 * This is a part of the Uniot project.
 * Copyright (C) 2016-2020 Uniot <contact@uniot.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <ClearQueue.h>

namespace uniot
{
template <class T_topic, class T_msg>
class EventBus;

template <class T_topic, class T_msg>
class EventListener
{
  friend class EventBus<T_topic, T_msg>;

public:
  virtual ~EventListener();

  EventListener *listenToEvent(T_topic topic);
  EventListener *stopListeningToEvent(T_topic topic);
  bool isListeningToEvent(T_topic topic);
  void connect(EventBus<T_topic, T_msg> *eventBus);
  void disconnect(EventBus<T_topic, T_msg> *eventBus);
  virtual void onEventReceived(T_topic topic, T_msg msg) = 0;

private:
  ClearQueue<EventBus<T_topic, T_msg> *> mEventBusQueue;
  ClearQueue<T_topic> mTopics;
};

using CoreEventListener = EventListener<unsigned int, int>;
} // namespace uniot