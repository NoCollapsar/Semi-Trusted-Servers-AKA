//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/Xiedmsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include "Xiedmsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace {
template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)(static_cast<const omnetpp::cObject *>(t));
}

template <class T> inline
typename std::enable_if<std::is_polymorphic<T>::value && !std::is_base_of<omnetpp::cObject,T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)dynamic_cast<const void *>(t);
}

template <class T> inline
typename std::enable_if<!std::is_polymorphic<T>::value, void *>::type
toVoidPtr(T* t)
{
    return (void *)static_cast<const void *>(t);
}

}

namespace veins {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule to generate operator<< for shared_ptr<T>
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const std::shared_ptr<T>& t) { return out << t.get(); }

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(XiedVmsg)

XiedVmsg::XiedVmsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

XiedVmsg::XiedVmsg(const XiedVmsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

XiedVmsg::~XiedVmsg()
{
}

XiedVmsg& XiedVmsg::operator=(const XiedVmsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void XiedVmsg::copy(const XiedVmsg& other)
{
    this->SHIDTE = other.SHIDTE;
    this->M1 = other.M1;
    this->M2 = other.M2;
    this->AUTE = other.AUTE;
    this->T1 = other.T1;
}

void XiedVmsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->SHIDTE);
    doParsimPacking(b,this->M1);
    doParsimPacking(b,this->M2);
    doParsimPacking(b,this->AUTE);
    doParsimPacking(b,this->T1);
}

void XiedVmsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->SHIDTE);
    doParsimUnpacking(b,this->M1);
    doParsimUnpacking(b,this->M2);
    doParsimUnpacking(b,this->AUTE);
    doParsimUnpacking(b,this->T1);
}

int XiedVmsg::getSHIDTE() const
{
    return this->SHIDTE;
}

void XiedVmsg::setSHIDTE(int SHIDTE)
{
    this->SHIDTE = SHIDTE;
}

int XiedVmsg::getM1() const
{
    return this->M1;
}

void XiedVmsg::setM1(int M1)
{
    this->M1 = M1;
}

int XiedVmsg::getM2() const
{
    return this->M2;
}

void XiedVmsg::setM2(int M2)
{
    this->M2 = M2;
}

int XiedVmsg::getAUTE() const
{
    return this->AUTE;
}

void XiedVmsg::setAUTE(int AUTE)
{
    this->AUTE = AUTE;
}

omnetpp::simtime_t XiedVmsg::getT1() const
{
    return this->T1;
}

void XiedVmsg::setT1(omnetpp::simtime_t T1)
{
    this->T1 = T1;
}

class XiedVmsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_SHIDTE,
        FIELD_M1,
        FIELD_M2,
        FIELD_AUTE,
        FIELD_T1,
    };
  public:
    XiedVmsgDescriptor();
    virtual ~XiedVmsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(XiedVmsgDescriptor)

XiedVmsgDescriptor::XiedVmsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::XiedVmsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

XiedVmsgDescriptor::~XiedVmsgDescriptor()
{
    delete[] propertynames;
}

bool XiedVmsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<XiedVmsg *>(obj)!=nullptr;
}

const char **XiedVmsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *XiedVmsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int XiedVmsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int XiedVmsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_SHIDTE
        FD_ISEDITABLE,    // FIELD_M1
        FD_ISEDITABLE,    // FIELD_M2
        FD_ISEDITABLE,    // FIELD_AUTE
        FD_ISEDITABLE,    // FIELD_T1
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *XiedVmsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SHIDTE",
        "M1",
        "M2",
        "AUTE",
        "T1",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int XiedVmsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'S' && strcmp(fieldName, "SHIDTE") == 0) return base+0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "M1") == 0) return base+1;
    if (fieldName[0] == 'M' && strcmp(fieldName, "M2") == 0) return base+2;
    if (fieldName[0] == 'A' && strcmp(fieldName, "AUTE") == 0) return base+3;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T1") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *XiedVmsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_SHIDTE
        "int",    // FIELD_M1
        "int",    // FIELD_M2
        "int",    // FIELD_AUTE
        "omnetpp::simtime_t",    // FIELD_T1
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **XiedVmsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *XiedVmsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int XiedVmsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    XiedVmsg *pp = (XiedVmsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *XiedVmsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedVmsg *pp = (XiedVmsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string XiedVmsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedVmsg *pp = (XiedVmsg *)object; (void)pp;
    switch (field) {
        case FIELD_SHIDTE: return long2string(pp->getSHIDTE());
        case FIELD_M1: return long2string(pp->getM1());
        case FIELD_M2: return long2string(pp->getM2());
        case FIELD_AUTE: return long2string(pp->getAUTE());
        case FIELD_T1: return simtime2string(pp->getT1());
        default: return "";
    }
}

bool XiedVmsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    XiedVmsg *pp = (XiedVmsg *)object; (void)pp;
    switch (field) {
        case FIELD_SHIDTE: pp->setSHIDTE(string2long(value)); return true;
        case FIELD_M1: pp->setM1(string2long(value)); return true;
        case FIELD_M2: pp->setM2(string2long(value)); return true;
        case FIELD_AUTE: pp->setAUTE(string2long(value)); return true;
        case FIELD_T1: pp->setT1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *XiedVmsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *XiedVmsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    XiedVmsg *pp = (XiedVmsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(XiedRMsg)

XiedRMsg::XiedRMsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

XiedRMsg::XiedRMsg(const XiedRMsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

XiedRMsg::~XiedRMsg()
{
}

XiedRMsg& XiedRMsg::operator=(const XiedRMsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void XiedRMsg::copy(const XiedRMsg& other)
{
    this->M6 = other.M6;
    this->IDCS = other.IDCS;
    this->AUS = other.AUS;
    this->T3 = other.T3;
}

void XiedRMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->M6);
    doParsimPacking(b,this->IDCS);
    doParsimPacking(b,this->AUS);
    doParsimPacking(b,this->T3);
}

void XiedRMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->M6);
    doParsimUnpacking(b,this->IDCS);
    doParsimUnpacking(b,this->AUS);
    doParsimUnpacking(b,this->T3);
}

int XiedRMsg::getM6() const
{
    return this->M6;
}

void XiedRMsg::setM6(int M6)
{
    this->M6 = M6;
}

int XiedRMsg::getIDCS() const
{
    return this->IDCS;
}

void XiedRMsg::setIDCS(int IDCS)
{
    this->IDCS = IDCS;
}

int XiedRMsg::getAUS() const
{
    return this->AUS;
}

void XiedRMsg::setAUS(int AUS)
{
    this->AUS = AUS;
}

omnetpp::simtime_t XiedRMsg::getT3() const
{
    return this->T3;
}

void XiedRMsg::setT3(omnetpp::simtime_t T3)
{
    this->T3 = T3;
}

class XiedRMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_M6,
        FIELD_IDCS,
        FIELD_AUS,
        FIELD_T3,
    };
  public:
    XiedRMsgDescriptor();
    virtual ~XiedRMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(XiedRMsgDescriptor)

XiedRMsgDescriptor::XiedRMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::XiedRMsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

XiedRMsgDescriptor::~XiedRMsgDescriptor()
{
    delete[] propertynames;
}

bool XiedRMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<XiedRMsg *>(obj)!=nullptr;
}

const char **XiedRMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *XiedRMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int XiedRMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int XiedRMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_M6
        FD_ISEDITABLE,    // FIELD_IDCS
        FD_ISEDITABLE,    // FIELD_AUS
        FD_ISEDITABLE,    // FIELD_T3
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *XiedRMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "M6",
        "IDCS",
        "AUS",
        "T3",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int XiedRMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "M6") == 0) return base+0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDCS") == 0) return base+1;
    if (fieldName[0] == 'A' && strcmp(fieldName, "AUS") == 0) return base+2;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T3") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *XiedRMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_M6
        "int",    // FIELD_IDCS
        "int",    // FIELD_AUS
        "omnetpp::simtime_t",    // FIELD_T3
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **XiedRMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *XiedRMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int XiedRMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    XiedRMsg *pp = (XiedRMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *XiedRMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedRMsg *pp = (XiedRMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string XiedRMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedRMsg *pp = (XiedRMsg *)object; (void)pp;
    switch (field) {
        case FIELD_M6: return long2string(pp->getM6());
        case FIELD_IDCS: return long2string(pp->getIDCS());
        case FIELD_AUS: return long2string(pp->getAUS());
        case FIELD_T3: return simtime2string(pp->getT3());
        default: return "";
    }
}

bool XiedRMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    XiedRMsg *pp = (XiedRMsg *)object; (void)pp;
    switch (field) {
        case FIELD_M6: pp->setM6(string2long(value)); return true;
        case FIELD_IDCS: pp->setIDCS(string2long(value)); return true;
        case FIELD_AUS: pp->setAUS(string2long(value)); return true;
        case FIELD_T3: pp->setT3(string2simtime(value)); return true;
        default: return false;
    }
}

const char *XiedRMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *XiedRMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    XiedRMsg *pp = (XiedRMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(XiedIDBroad)

XiedIDBroad::XiedIDBroad(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

XiedIDBroad::XiedIDBroad(const XiedIDBroad& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

XiedIDBroad::~XiedIDBroad()
{
}

XiedIDBroad& XiedIDBroad::operator=(const XiedIDBroad& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void XiedIDBroad::copy(const XiedIDBroad& other)
{
    this->R = other.R;
    this->Name = other.Name;
}

void XiedIDBroad::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->R);
    doParsimPacking(b,this->Name);
}

void XiedIDBroad::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->R);
    doParsimUnpacking(b,this->Name);
}

int XiedIDBroad::getR() const
{
    return this->R;
}

void XiedIDBroad::setR(int R)
{
    this->R = R;
}

const char * XiedIDBroad::getName() const
{
    return this->Name.c_str();
}

void XiedIDBroad::setName(const char * Name)
{
    this->Name = Name;
}

class XiedIDBroadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_R,
        FIELD_Name,
    };
  public:
    XiedIDBroadDescriptor();
    virtual ~XiedIDBroadDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(XiedIDBroadDescriptor)

XiedIDBroadDescriptor::XiedIDBroadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::XiedIDBroad)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

XiedIDBroadDescriptor::~XiedIDBroadDescriptor()
{
    delete[] propertynames;
}

bool XiedIDBroadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<XiedIDBroad *>(obj)!=nullptr;
}

const char **XiedIDBroadDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *XiedIDBroadDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int XiedIDBroadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int XiedIDBroadDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_R
        FD_ISEDITABLE,    // FIELD_Name
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *XiedIDBroadDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "R",
        "Name",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int XiedIDBroadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "R") == 0) return base+0;
    if (fieldName[0] == 'N' && strcmp(fieldName, "Name") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *XiedIDBroadDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_R
        "string",    // FIELD_Name
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **XiedIDBroadDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *XiedIDBroadDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int XiedIDBroadDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    XiedIDBroad *pp = (XiedIDBroad *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *XiedIDBroadDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedIDBroad *pp = (XiedIDBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string XiedIDBroadDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    XiedIDBroad *pp = (XiedIDBroad *)object; (void)pp;
    switch (field) {
        case FIELD_R: return long2string(pp->getR());
        case FIELD_Name: return oppstring2string(pp->getName());
        default: return "";
    }
}

bool XiedIDBroadDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    XiedIDBroad *pp = (XiedIDBroad *)object; (void)pp;
    switch (field) {
        case FIELD_R: pp->setR(string2long(value)); return true;
        case FIELD_Name: pp->setName((value)); return true;
        default: return false;
    }
}

const char *XiedIDBroadDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *XiedIDBroadDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    XiedIDBroad *pp = (XiedIDBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

