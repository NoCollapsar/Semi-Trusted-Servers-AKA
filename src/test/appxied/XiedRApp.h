#pragma once

#include "veins/veins.h"
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/test/messages/Xiedmsg_m.h"
using namespace omnetpp;

namespace veins {

class XiedRApp : public DemoBaseApplLayer {
public:
    virtual void initialize(int stage) override;
    virtual void finish() override;

protected:
    virtual void handleLowerMsg(cMessage* msg) override;
    virtual void handleSelfMsg(cMessage* msg) override;

    // 自定义函数
    int h(int input);  // 原 hashFunction
    // 成员变量
   int RID ;   // RSU ID
   int ASj=8 ; // 预定义的 ASj值
   int Q=8;
   int allowedDelay = 10;       // 时间戳允许的最大延迟
    cMessage* sendrid;
};

}

















