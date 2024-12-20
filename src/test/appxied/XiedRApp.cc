#include "veins/test/appxied/XiedRApp.h"
#include "veins/test/messages/Xiedmsg_m.h"
#include <omnetpp.h>
#include <cmath>
#include <openssl/sha.h>
using namespace veins;

Define_Module(XiedRApp);


void XiedRApp::initialize(int stage) {
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        sendrid = new cMessage("send message");
        EV << "Initializing RSU" << std::endl;
    }
    else if (stage == 1) {
        if (sendrid->isScheduled()) {
            cancelEvent(sendrid);
        }
        allowedDelay = 10;
        scheduleAt(simTime() + 1, sendrid);
    }
}
 void XiedRApp::handleSelfMsg(cMessage* msg)
 {
     if(msg==sendrid)
     {// 创建广播消息，并设置 ID 参数
         XiedIDBroad* idBroadcastMsg = new XiedIDBroad();
             int R;
             R=getId();
             idBroadcastMsg->setR(R) ; // 添加 RSU 的 ID 参数
             BaseFrame1609_4* idmsg = new BaseFrame1609_4();
                          //把vmsg封装在WSM中
                            idmsg->encapsulate(idBroadcastMsg);
                              //设置WSM的基本信息
                       populateWSM(idmsg);
             // 通过广播发送消息，假设 sendBroadcast 函数实现了广播机制
             send(idmsg,lowerLayerOut);
             EV << "RSU ID broadcast sent with RID=" << getId() << endl;
            // scheduleAt(simTime()+5,sendrid);
     }
 }

 void XiedRApp::finish() {
     DemoBaseApplLayer::finish();
 }

void XiedRApp::handleLowerMsg(cMessage* msg) {

    BaseFrame1609_4* WSM = check_and_cast<BaseFrame1609_4*>(msg);
           XiedVmsg* vmsg = dynamic_cast<XiedVmsg*>(WSM->getEncapsulatedPacket());
           if (vmsg) {


                int SHIDTE=int(vmsg->getSHIDTE());
                ASj=8;
                 int T1=static_cast<int>(std::round(vmsg->getT1().dbl()));
                 int M1=int(vmsg->getM1()) ;
                  int M2=int(vmsg->getM2());
                  int AUTE=int(vmsg->getAUTE());
                  int SV1=h(Q);
                  int SV2=h(ASj+Q);
                  int ARG2=h(ASj+SV1);
                  int x1=M1-ARG2;
                  int HIDTE=SHIDTE-x1-ARG2;
                  EV << "Received message from VID: " << HIDTE << endl;
                  int Aij=h(HIDTE+SV2);
                  int x2=M2-h(Aij+x1);
                  int M3=h(HIDTE+x1+x2);
                  //EV << "SV1="<< SV1  << endl;
                  //EV << "SV2="<< SV2  << endl;
                     //EV << "T1=" << static_cast<int>(std::round(m1->getT1().dbl())) << endl;


                  if (AUTE != h(HIDTE+ASj+M3+T1)) {
                              EV << "Verification failed, stopping service." << endl;
                              return ;

                  }
                  // 生成并发送 M2
                     int M4=h(HIDTE+ASj+x1+x2+Aij);
                      int y = intuniform(1, 10000);
                         simtime_t t2 = simTime();
                           int T2=static_cast<int>(std::round(t2.dbl()));
                           int IDCS=getId();
                          int M6=y+M4;
                          int SKik=h(M4+ASj+IDCS+y+T2);
                          int AUS=h(SKik+M4+y);
                              XiedRMsg* csmsg = new XiedRMsg("CSMSG");
                                csmsg->setM6(M6);
                                csmsg->setAUS(AUS);
                                csmsg->setT3(T2);
                                csmsg->setIDCS(IDCS);
                        //fengzhuang
                           BaseFrame1609_4* WSM2 = new BaseFrame1609_4();
                                  //把vmsg封装在WSM中
                                  WSM2->encapsulate(csmsg);
                                   //设置WSM的基本信息
                                     populateWSM(WSM2);
                                       send(WSM2,lowerLayerOut);
                                  EV << "RID="<< RID << " send M2 to VID=" << HIDTE<< endl;

           }



}

int XiedRApp::h(int input) {
    // 简单的哈希示例
    unsigned char hash[SHA256_DIGEST_LENGTH];
         SHA256_CTX sha256;
         SHA256_Init(&sha256);

         // 将输入 int 转换为字节数组
         unsigned char input_bytes[sizeof(int)];
         for (int i = 0; i < sizeof(int); ++i) {
             input_bytes[i] = (input >> (i * 8)) & 0xFF;  // 按字节拆分
         }

         // 计算 SHA-256 哈希
         SHA256_Update(&sha256, input_bytes, sizeof(input_bytes));
         SHA256_Final(hash, &sha256);

         // 将前 4 字节转换为一个 int 作为最终哈希值
         int hash_int = 0;
         for (int i = 0; i < 4; ++i) {
             hash_int = (hash_int << 8) | hash[i];
         }

         return hash_int;

}

