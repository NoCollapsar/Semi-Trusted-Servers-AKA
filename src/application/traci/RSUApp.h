#pragma once

#include "veins/veins.h"
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/modules/application/traci/KeyExchangeMessage_m.h"

using namespace omnetpp;

namespace veins {

class VEINS_API RSUApp : public DemoBaseApplLayer {
public:
    void initialize(int stage) override;
    void finish() override;

protected:
    void handleLowerMsg(cMessage* msg) override;
    cOutVector vIndex;
    int a;
};

} // namespace veins
