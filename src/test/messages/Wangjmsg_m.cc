//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/Wangjmsg.msg.
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
#include "Wangjmsg_m.h"

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

Register_Class(VMsg)

VMsg::VMsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

VMsg::VMsg(const VMsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

VMsg::~VMsg()
{
}

VMsg& VMsg::operator=(const VMsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void VMsg::copy(const VMsg& other)
{
    this->Ri = other.Ri;
    this->Pi = other.Pi;
    this->vi = other.vi;
    this->Xi = other.Xi;
    this->dui = other.dui;
    this->T1 = other.T1;
}

void VMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->Ri);
    doParsimPacking(b,this->Pi);
    doParsimPacking(b,this->vi);
    doParsimPacking(b,this->Xi);
    doParsimPacking(b,this->dui);
    doParsimPacking(b,this->T1);
}

void VMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->Ri);
    doParsimUnpacking(b,this->Pi);
    doParsimUnpacking(b,this->vi);
    doParsimUnpacking(b,this->Xi);
    doParsimUnpacking(b,this->dui);
    doParsimUnpacking(b,this->T1);
}

int VMsg::getRi() const
{
    return this->Ri;
}

void VMsg::setRi(int Ri)
{
    this->Ri = Ri;
}

int VMsg::getPi() const
{
    return this->Pi;
}

void VMsg::setPi(int Pi)
{
    this->Pi = Pi;
}

int VMsg::getVi() const
{
    return this->vi;
}

void VMsg::setVi(int vi)
{
    this->vi = vi;
}

int VMsg::getXi() const
{
    return this->Xi;
}

void VMsg::setXi(int Xi)
{
    this->Xi = Xi;
}

int VMsg::getDui() const
{
    return this->dui;
}

void VMsg::setDui(int dui)
{
    this->dui = dui;
}

omnetpp::simtime_t VMsg::getT1() const
{
    return this->T1;
}

void VMsg::setT1(omnetpp::simtime_t T1)
{
    this->T1 = T1;
}

class VMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_Ri,
        FIELD_Pi,
        FIELD_vi,
        FIELD_Xi,
        FIELD_dui,
        FIELD_T1,
    };
  public:
    VMsgDescriptor();
    virtual ~VMsgDescriptor();

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

Register_ClassDescriptor(VMsgDescriptor)

VMsgDescriptor::VMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::VMsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

VMsgDescriptor::~VMsgDescriptor()
{
    delete[] propertynames;
}

bool VMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VMsg *>(obj)!=nullptr;
}

const char **VMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *VMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int VMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int VMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_Ri
        FD_ISEDITABLE,    // FIELD_Pi
        FD_ISEDITABLE,    // FIELD_vi
        FD_ISEDITABLE,    // FIELD_Xi
        FD_ISEDITABLE,    // FIELD_dui
        FD_ISEDITABLE,    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *VMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Ri",
        "Pi",
        "vi",
        "Xi",
        "dui",
        "T1",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int VMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "Ri") == 0) return base+0;
    if (fieldName[0] == 'P' && strcmp(fieldName, "Pi") == 0) return base+1;
    if (fieldName[0] == 'v' && strcmp(fieldName, "vi") == 0) return base+2;
    if (fieldName[0] == 'X' && strcmp(fieldName, "Xi") == 0) return base+3;
    if (fieldName[0] == 'd' && strcmp(fieldName, "dui") == 0) return base+4;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T1") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *VMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_Ri
        "int",    // FIELD_Pi
        "int",    // FIELD_vi
        "int",    // FIELD_Xi
        "int",    // FIELD_dui
        "omnetpp::simtime_t",    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **VMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *VMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int VMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    VMsg *pp = (VMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *VMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VMsg *pp = (VMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VMsg *pp = (VMsg *)object; (void)pp;
    switch (field) {
        case FIELD_Ri: return long2string(pp->getRi());
        case FIELD_Pi: return long2string(pp->getPi());
        case FIELD_vi: return long2string(pp->getVi());
        case FIELD_Xi: return long2string(pp->getXi());
        case FIELD_dui: return long2string(pp->getDui());
        case FIELD_T1: return simtime2string(pp->getT1());
        default: return "";
    }
}

bool VMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    VMsg *pp = (VMsg *)object; (void)pp;
    switch (field) {
        case FIELD_Ri: pp->setRi(string2long(value)); return true;
        case FIELD_Pi: pp->setPi(string2long(value)); return true;
        case FIELD_vi: pp->setVi(string2long(value)); return true;
        case FIELD_Xi: pp->setXi(string2long(value)); return true;
        case FIELD_dui: pp->setDui(string2long(value)); return true;
        case FIELD_T1: pp->setT1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *VMsgDescriptor::getFieldStructName(int field) const
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

void *VMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    VMsg *pp = (VMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CMsg)

CMsg::CMsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

CMsg::CMsg(const CMsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

CMsg::~CMsg()
{
}

CMsg& CMsg::operator=(const CMsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void CMsg::copy(const CMsg& other)
{
    this->Rj = other.Rj;
    this->MAC = other.MAC;
    this->IDSj = other.IDSj;
    this->PSj = other.PSj;
    this->T2 = other.T2;
}

void CMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->Rj);
    doParsimPacking(b,this->MAC);
    doParsimPacking(b,this->IDSj);
    doParsimPacking(b,this->PSj);
    doParsimPacking(b,this->T2);
}

void CMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->Rj);
    doParsimUnpacking(b,this->MAC);
    doParsimUnpacking(b,this->IDSj);
    doParsimUnpacking(b,this->PSj);
    doParsimUnpacking(b,this->T2);
}

int CMsg::getRj() const
{
    return this->Rj;
}

void CMsg::setRj(int Rj)
{
    this->Rj = Rj;
}

int CMsg::getMAC() const
{
    return this->MAC;
}

void CMsg::setMAC(int MAC)
{
    this->MAC = MAC;
}

int CMsg::getIDSj() const
{
    return this->IDSj;
}

void CMsg::setIDSj(int IDSj)
{
    this->IDSj = IDSj;
}

int CMsg::getPSj() const
{
    return this->PSj;
}

void CMsg::setPSj(int PSj)
{
    this->PSj = PSj;
}

omnetpp::simtime_t CMsg::getT2() const
{
    return this->T2;
}

void CMsg::setT2(omnetpp::simtime_t T2)
{
    this->T2 = T2;
}

class CMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_Rj,
        FIELD_MAC,
        FIELD_IDSj,
        FIELD_PSj,
        FIELD_T2,
    };
  public:
    CMsgDescriptor();
    virtual ~CMsgDescriptor();

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

Register_ClassDescriptor(CMsgDescriptor)

CMsgDescriptor::CMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::CMsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

CMsgDescriptor::~CMsgDescriptor()
{
    delete[] propertynames;
}

bool CMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CMsg *>(obj)!=nullptr;
}

const char **CMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int CMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_Rj
        FD_ISEDITABLE,    // FIELD_MAC
        FD_ISEDITABLE,    // FIELD_IDSj
        FD_ISEDITABLE,    // FIELD_PSj
        FD_ISEDITABLE,    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *CMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Rj",
        "MAC",
        "IDSj",
        "PSj",
        "T2",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int CMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "Rj") == 0) return base+0;
    if (fieldName[0] == 'M' && strcmp(fieldName, "MAC") == 0) return base+1;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDSj") == 0) return base+2;
    if (fieldName[0] == 'P' && strcmp(fieldName, "PSj") == 0) return base+3;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T2") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_Rj
        "int",    // FIELD_MAC
        "int",    // FIELD_IDSj
        "int",    // FIELD_PSj
        "omnetpp::simtime_t",    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **CMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *CMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int CMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CMsg *pp = (CMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CMsg *pp = (CMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CMsg *pp = (CMsg *)object; (void)pp;
    switch (field) {
        case FIELD_Rj: return long2string(pp->getRj());
        case FIELD_MAC: return long2string(pp->getMAC());
        case FIELD_IDSj: return long2string(pp->getIDSj());
        case FIELD_PSj: return long2string(pp->getPSj());
        case FIELD_T2: return simtime2string(pp->getT2());
        default: return "";
    }
}

bool CMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CMsg *pp = (CMsg *)object; (void)pp;
    switch (field) {
        case FIELD_Rj: pp->setRj(string2long(value)); return true;
        case FIELD_MAC: pp->setMAC(string2long(value)); return true;
        case FIELD_IDSj: pp->setIDSj(string2long(value)); return true;
        case FIELD_PSj: pp->setPSj(string2long(value)); return true;
        case FIELD_T2: pp->setT2(string2simtime(value)); return true;
        default: return false;
    }
}

const char *CMsgDescriptor::getFieldStructName(int field) const
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

void *CMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CMsg *pp = (CMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(WJBroad)

WJBroad::WJBroad(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

WJBroad::WJBroad(const WJBroad& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

WJBroad::~WJBroad()
{
}

WJBroad& WJBroad::operator=(const WJBroad& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void WJBroad::copy(const WJBroad& other)
{
    this->IDSj = other.IDSj;
    this->PSj = other.PSj;
}

void WJBroad::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->IDSj);
    doParsimPacking(b,this->PSj);
}

void WJBroad::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->IDSj);
    doParsimUnpacking(b,this->PSj);
}

int WJBroad::getIDSj() const
{
    return this->IDSj;
}

void WJBroad::setIDSj(int IDSj)
{
    this->IDSj = IDSj;
}

int WJBroad::getPSj() const
{
    return this->PSj;
}

void WJBroad::setPSj(int PSj)
{
    this->PSj = PSj;
}

class WJBroadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_IDSj,
        FIELD_PSj,
    };
  public:
    WJBroadDescriptor();
    virtual ~WJBroadDescriptor();

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

Register_ClassDescriptor(WJBroadDescriptor)

WJBroadDescriptor::WJBroadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::WJBroad)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

WJBroadDescriptor::~WJBroadDescriptor()
{
    delete[] propertynames;
}

bool WJBroadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WJBroad *>(obj)!=nullptr;
}

const char **WJBroadDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *WJBroadDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int WJBroadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int WJBroadDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_IDSj
        FD_ISEDITABLE,    // FIELD_PSj
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *WJBroadDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "IDSj",
        "PSj",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int WJBroadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDSj") == 0) return base+0;
    if (fieldName[0] == 'P' && strcmp(fieldName, "PSj") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *WJBroadDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_IDSj
        "int",    // FIELD_PSj
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **WJBroadDescriptor::getFieldPropertyNames(int field) const
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

const char *WJBroadDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int WJBroadDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    WJBroad *pp = (WJBroad *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *WJBroadDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WJBroad *pp = (WJBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WJBroadDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WJBroad *pp = (WJBroad *)object; (void)pp;
    switch (field) {
        case FIELD_IDSj: return long2string(pp->getIDSj());
        case FIELD_PSj: return long2string(pp->getPSj());
        default: return "";
    }
}

bool WJBroadDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    WJBroad *pp = (WJBroad *)object; (void)pp;
    switch (field) {
        case FIELD_IDSj: pp->setIDSj(string2long(value)); return true;
        case FIELD_PSj: pp->setPSj(string2long(value)); return true;
        default: return false;
    }
}

const char *WJBroadDescriptor::getFieldStructName(int field) const
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

void *WJBroadDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    WJBroad *pp = (WJBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

