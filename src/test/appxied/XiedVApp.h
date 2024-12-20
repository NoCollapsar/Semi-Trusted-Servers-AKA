
#include "veins/veins.h"
#include <vector>
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/test/messages/Xiedmsg_m.h"
#include <openssl/sha.h>
#include <cmath>
using namespace omnetpp;

namespace veins {

class VEINS_API XiedVApp : public DemoBaseApplLayer{
public:
      virtual void initialize(int stage) override;
     virtual void finish() override;
protected:
     virtual void handleSelfMsg(cMessage* msg) override;
      virtual void handleLowerMsg(cMessage* msg) override;
    // 自定义函数

    int h(int input);


    simtime_t T1;
   int Q=8;
    int ASj=8;
    int x1= 16;
    int x2 = 20;
    //int x2 = intuniform(1, 10000);
    cMessage* sendvMsg;       // 定时发送 M1 消息的定时器
    int allowedDelay = 10;
};
}
