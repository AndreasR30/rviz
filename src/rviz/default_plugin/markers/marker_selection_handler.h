/*
 * Copyright (c) 2009, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_MARKER_SELECTION_HANDLER_H
#define RVIZ_MARKER_SELECTION_HANDLER_H

#include "rviz/selection/forwards.h"
#include "rviz/selection/selection_manager.h"

namespace rviz
{
class InteractiveMarkerControl;
class MarkerBase;
typedef std::pair<std::string, int32_t> MarkerID;

class MarkerSelectionHandler : public SelectionHandler
{
public:
  MarkerSelectionHandler(const MarkerBase* marker, MarkerID id);
  virtual ~MarkerSelectionHandler();

  std::string getId()
  {
    std::stringstream ss;
    ss << id_.first << "/" << id_.second;
    return ss.str();
  }

  Ogre::Vector3 getPosition();
  Ogre::Quaternion getOrientation();

  void setControl( InteractiveMarkerControl* control );

  // called when interactive mode is globally switched on/off
  virtual void enableInteraction(bool enable);

  // @return true if this handler is ready to receive mouse events
  virtual bool isInteractive();

  // is called when the mouse passes over the object
  virtual void onReceiveFocus(const Picked& obj);

  // is called when the mouse leaves the object or when draggging is finished
  virtual void onLoseFocus(const Picked& obj);

  // will receive all mouse events while the handler has focus
  virtual void handleMouseEvent(const Picked& obj, ViewportMouseEvent& event);

  virtual void createProperties(const Picked& obj, PropertyManager* property_manager);

private:
  const MarkerBase* marker_;
  MarkerID id_;
  InteractiveMarkerControl* control_;
};

}

#endif
