#include "veins/test/messages/Xiedmsg_m.h"
#include <omnetpp.h>
#include <veins/test/appxied/XiedVApp.h>
#include <openssl/sha.h>
#include <cmath>


using namespace veins;

Define_Module(XiedVApp);

void XiedVApp::initialize(int stage) {
    DemoBaseApplLayer::initialize(stage);

    }

void XiedVApp::finish()
{
    DemoBaseApplLayer::finish();
    // statistics recording goes here
}

void XiedVApp::handleSelfMsg(cMessage* msg) {
    DemoBaseApplLayer::handleSelfMsg(msg);
}

void XiedVApp::handleLowerMsg(cMessage* msg) {
    BaseFrame1609_4* WSM3 = check_and_cast<BaseFrame1609_4*>(msg);
                    //从WSM中解封数据包
                    cPacket* enc = WSM3->getEncapsulatedPacket();
                    //数据包转换成BeaconRSU
                    simtime_t ST,ET;
       if(XiedIDBroad* m1=dynamic_cast<XiedIDBroad*>(enc))
                            {//EV << "message name:=" << m2->getName() << endl;
                               ST=simTime();
                                   // 处理 RSU 的 ID 广播消息
                  int IDCS = m1->getR();
                EV << "Start time=" << ST << endl;
               EV << "Received CS ID broadcast with IDCS=" << IDCS << endl;
              int T1=static_cast<int>(std::round(ST.dbl()));

             int HIDTE=getId();
             int Vi=8;
             int PWTE=8;
             int RTE=8;
             int  ARG1=Vi+h(HIDTE+PWTE+RTE);
             int SV1=h(Q);
             int ARG2=h(ASj+SV1);
             int SHIDTE=HIDTE+x1+ARG2;
             int SV2=h(ASj+Q);
             int  Aij=h(HIDTE+SV2);
             int M1=ARG2+x1;
             int M2=h(Aij+x1)+x2;
             int M3=h(HIDTE+x1+x2);
             int AUTE=h(HIDTE+ASj+M3+T1);
             //EV << "HIDTE="<< HIDTE  << endl;
                   XiedVmsg* vsend = new XiedVmsg();
                                  vsend->setSHIDTE(SHIDTE);
                                   vsend->setM1(M1);
                                   vsend->setM2(M2);
                                vsend->setAUTE(AUTE);
                                 vsend->setT1(ST);
                          // 新建WSM，这是应用层和MAC层通信的消息
                              BaseFrame1609_4* WSM = new BaseFrame1609_4();
                            //把vmsg封装在WSM中
                             WSM->encapsulate(vsend);
                              //设置WSM的基本信息
                                    populateWSM(WSM);
                                 send(WSM,lowerLayerOut);
                          EV << "VID="<< HIDTE <<" send M to CS." << endl;
               }

       else  if(XiedRMsg* m2 = dynamic_cast<XiedRMsg*>(enc)){

                                 // 检查时间戳和验证W3
                                  if (simTime() - m2->getT3() > allowedDelay) {
                                      EV << "Timestamp invalid, discarding M2." << endl;
                                   return;
                        }
                   int M6=m2->getM6();
                     int AUS=m2->getAUS();
                     int IDCS=m2->getIDCS();
                     simtime_t t3=m2->getT3();
                     int T3=static_cast<int>(std::round(t3.dbl()));
                    // EV << "TVNI="<< TVNi<< endl;
                     int HIDTE=getId();
                     int SV2=h(Q+ASj);
                      int  Aij=h(HIDTE+SV2);
                    int M4=h(HIDTE+ASj+x1+x2+Aij);
                    int y=M6-M4;
                    int SKik=h(M4+ASj+IDCS+y+T3);
                          if (AUS!=h(SKik+M4+y)) {
                           EV << "verification failed, stopping session." << endl;
                             return;
                        }
                       ET=simTime();
                       EV<< "End time=" << ET << endl;
                       EV <<"VID="<< HIDTE <<"with IDCS="<< IDCS << " established  SKIJ successfully: " << SKik << endl;
                       }
}




int XiedVApp::h(int input) {
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

