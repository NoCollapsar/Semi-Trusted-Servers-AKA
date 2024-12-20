//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/Wangjmsg.msg.
//

#ifndef __VEINS_WANGJMSG_M_H
#define __VEINS_WANGJMSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0507
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef VEINS_API
#  if defined(VEINS_EXPORT)
#    define VEINS_API  OPP_DLLEXPORT
#  elif defined(VEINS_IMPORT)
#    define VEINS_API  OPP_DLLIMPORT
#  else
#    define VEINS_API
#  endif
#endif


namespace veins {

class VMsg;
class CMsg;
class WJBroad;
} // namespace veins

#include "veins/base/utils/Coord_m.h" // import veins.base.utils.Coord

#include "veins/modules/messages/BaseFrame1609_4_m.h" // import veins.modules.messages.BaseFrame1609_4

#include "veins/base/utils/SimpleAddress_m.h" // import veins.base.utils.SimpleAddress


namespace veins {

/**
 * Class generated from <tt>veins/test/messages/Wangjmsg.msg:21</tt> by nedtool.
 * <pre>
 * packet VMsg extends BaseFrame1609_4
 * {
 *     int Ri;        // 
 *     int Pi;
 *     int vi;
 *     int Xi;
 *     int dui;
 * 
 *     simtime_t T1;      // 时间戳 T1
 * }
 * </pre>
 */
class VEINS_API VMsg : public ::veins::BaseFrame1609_4
{
  protected:
    int Ri = 0;
    int Pi = 0;
    int vi = 0;
    int Xi = 0;
    int dui = 0;
    omnetpp::simtime_t T1 = SIMTIME_ZERO;

  private:
    void copy(const VMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const VMsg&);

  public:
    VMsg(const char *name=nullptr, short kind=0);
    VMsg(const VMsg& other);
    virtual ~VMsg();
    VMsg& operator=(const VMsg& other);
    virtual VMsg *dup() const override {return new VMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getRi() const;
    virtual void setRi(int Ri);
    virtual int getPi() const;
    virtual void setPi(int Pi);
    virtual int getVi() const;
    virtual void setVi(int vi);
    virtual int getXi() const;
    virtual void setXi(int Xi);
    virtual int getDui() const;
    virtual void setDui(int dui);
    virtual omnetpp::simtime_t getT1() const;
    virtual void setT1(omnetpp::simtime_t T1);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const VMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, VMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>veins/test/messages/Wangjmsg.msg:31</tt> by nedtool.
 * <pre>
 * packet CMsg extends BaseFrame1609_4
 * {
 *     int Rj;
 *     int MAC;
 *     int IDSj;
 *     int PSj;
 *     simtime_t T2;      // 时间戳 T2
 * }
 * </pre>
 */
class VEINS_API CMsg : public ::veins::BaseFrame1609_4
{
  protected:
    int Rj = 0;
    int MAC = 0;
    int IDSj = 0;
    int PSj = 0;
    omnetpp::simtime_t T2 = SIMTIME_ZERO;

  private:
    void copy(const CMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CMsg&);

  public:
    CMsg(const char *name=nullptr, short kind=0);
    CMsg(const CMsg& other);
    virtual ~CMsg();
    CMsg& operator=(const CMsg& other);
    virtual CMsg *dup() const override {return new CMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getRj() const;
    virtual void setRj(int Rj);
    virtual int getMAC() const;
    virtual void setMAC(int MAC);
    virtual int getIDSj() const;
    virtual void setIDSj(int IDSj);
    virtual int getPSj() const;
    virtual void setPSj(int PSj);
    virtual omnetpp::simtime_t getT2() const;
    virtual void setT2(omnetpp::simtime_t T2);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>veins/test/messages/Wangjmsg.msg:39</tt> by nedtool.
 * <pre>
 * packet WJBroad extends BaseFrame1609_4
 * {
 *     int IDSj;       // RSU ID
 *     int PSj;  //gongyao
 * 
 * 
 * }
 * </pre>
 */
class VEINS_API WJBroad : public ::veins::BaseFrame1609_4
{
  protected:
    int IDSj = 0;
    int PSj = 0;

  private:
    void copy(const WJBroad& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const WJBroad&);

  public:
    WJBroad(const char *name=nullptr, short kind=0);
    WJBroad(const WJBroad& other);
    virtual ~WJBroad();
    WJBroad& operator=(const WJBroad& other);
    virtual WJBroad *dup() const override {return new WJBroad(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getIDSj() const;
    virtual void setIDSj(int IDSj);
    virtual int getPSj() const;
    virtual void setPSj(int PSj);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const WJBroad& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, WJBroad& obj) {obj.parsimUnpack(b);}

} // namespace veins

#endif // ifndef __VEINS_WANGJMSG_M_H

