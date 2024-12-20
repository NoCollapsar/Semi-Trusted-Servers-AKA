//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins/modules/application/traci/VehicleApp.h"

using namespace veins;

Define_Module(veins::VehicleApp);


void VehicleApp::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        // Initializing members and pointers of your application goes here
        sendmessage=new cMessage("send message");
        EV << "Initializing v"  << std::endl;
    }
    else if (stage == 1) {
        // Initializing members that require initialized other modules goes here
              if (sendmessage->isScheduled()) {
                    cancelEvent(sendmessage);
             }
              EV << "Initializing get"  << std::endl;
        scheduleAt(simTime()+5,sendmessage);
        EV << "Initializing haha"  << std::endl;
    }
}
void VehicleApp::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void VehicleApp::handleSelfMsg(cMessage* msg)
{

    // this method is for self messages (mostly timers)
    // it is important to call the DemoBaseApplLayer function for BSM and WSM transmission
    if(msg==sendmessage)
    {
        KeyExchangeMessage* vmsg=new KeyExchangeMessage();
        vmsg->setVehicleId(this->getParentModule()->getIndex());
        vmsg->setMydata("v message!");
        // 新建WSM，这是应用层和MAC层通信的消息
        BaseFrame1609_4* WSM = new BaseFrame1609_4();
         //把vmsg封装在WSM中
           WSM->encapsulate(vmsg);
            //设置WSM的基本信息
            populateWSM(WSM);
             send(WSM,lowerLayerOut);
             EV << "v send success" <<endl;

           return;

    }
}


void VehicleApp::handlePositionUpdate(cObject* obj)
{
    DemoBaseApplLayer::handlePositionUpdate(obj);
    // the vehicle has moved. Code that reacts to new positions goes here.
    // member variables such as currentPosition and currentSpeed are updated in the parent class
}
