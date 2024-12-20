

#include <veins/modules/application/traci/RSUApp.h>
#include "veins/modules/application/traci/KeyExchangeMessage_m.h"

using namespace veins;

Define_Module(veins::RSUApp);


void RSUApp::initialize(int stage)
{
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        EV << "Initializing rsu"  << std::endl;
        int a = INT_MIN;
    }
    else if (stage == 1) {
        vIndex.setName("test");
        int a = INT_MIN;
    }
}

void RSUApp::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void RSUApp::handleLowerMsg(cMessage* msg) {
    EV << "receive message  !!!" << endl;
    //消息传换成WSM
    BaseFrame1609_4* WSM = check_and_cast<BaseFrame1609_4*>(msg);
    //从WSM中解封数据包
    cPacket* enc = WSM->getEncapsulatedPacket();
    //数据包转换成BeaconRSU
    KeyExchangeMessage* bc = dynamic_cast<KeyExchangeMessage*>(enc);

    if(a!=bc->getVehicleId()){
       vIndex.record(bc->getVehicleId());
       a=bc->getVehicleId();
  }

  EV << "my message = " <<bc->getMydata()<<endl;
  EV <<"send message V id:" <<bc->getVehicleId() << "  Receive successfully !!!!!!!!!!!" << endl;
}
