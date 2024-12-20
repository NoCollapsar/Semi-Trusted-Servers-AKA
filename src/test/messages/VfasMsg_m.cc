//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/VfasMsg.msg.
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
#include "VfasMsg_m.h"

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

Register_Class(VfasVmsg)

VfasVmsg::VfasVmsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

VfasVmsg::VfasVmsg(const VfasVmsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

VfasVmsg::~VfasVmsg()
{
}

VfasVmsg& VfasVmsg::operator=(const VfasVmsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void VfasVmsg::copy(const VfasVmsg& other)
{
    this->PIDi = other.PIDi;
    this->Xi = other.Xi;
    this->Ai = other.Ai;
    this->Bi = other.Bi;
    this->Ci1 = other.Ci1;
    this->T1 = other.T1;
}

void VfasVmsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->PIDi);
    doParsimPacking(b,this->Xi);
    doParsimPacking(b,this->Ai);
    doParsimPacking(b,this->Bi);
    doParsimPacking(b,this->Ci1);
    doParsimPacking(b,this->T1);
}

void VfasVmsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->PIDi);
    doParsimUnpacking(b,this->Xi);
    doParsimUnpacking(b,this->Ai);
    doParsimUnpacking(b,this->Bi);
    doParsimUnpacking(b,this->Ci1);
    doParsimUnpacking(b,this->T1);
}

int VfasVmsg::getPIDi() const
{
    return this->PIDi;
}

void VfasVmsg::setPIDi(int PIDi)
{
    this->PIDi = PIDi;
}

int VfasVmsg::getXi() const
{
    return this->Xi;
}

void VfasVmsg::setXi(int Xi)
{
    this->Xi = Xi;
}

int VfasVmsg::getAi() const
{
    return this->Ai;
}

void VfasVmsg::setAi(int Ai)
{
    this->Ai = Ai;
}

int VfasVmsg::getBi() const
{
    return this->Bi;
}

void VfasVmsg::setBi(int Bi)
{
    this->Bi = Bi;
}

int VfasVmsg::getCi1() const
{
    return this->Ci1;
}

void VfasVmsg::setCi1(int Ci1)
{
    this->Ci1 = Ci1;
}

omnetpp::simtime_t VfasVmsg::getT1() const
{
    return this->T1;
}

void VfasVmsg::setT1(omnetpp::simtime_t T1)
{
    this->T1 = T1;
}

class VfasVmsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_PIDi,
        FIELD_Xi,
        FIELD_Ai,
        FIELD_Bi,
        FIELD_Ci1,
        FIELD_T1,
    };
  public:
    VfasVmsgDescriptor();
    virtual ~VfasVmsgDescriptor();

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

Register_ClassDescriptor(VfasVmsgDescriptor)

VfasVmsgDescriptor::VfasVmsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::VfasVmsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

VfasVmsgDescriptor::~VfasVmsgDescriptor()
{
    delete[] propertynames;
}

bool VfasVmsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VfasVmsg *>(obj)!=nullptr;
}

const char **VfasVmsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *VfasVmsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int VfasVmsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int VfasVmsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_PIDi
        FD_ISEDITABLE,    // FIELD_Xi
        FD_ISEDITABLE,    // FIELD_Ai
        FD_ISEDITABLE,    // FIELD_Bi
        FD_ISEDITABLE,    // FIELD_Ci1
        FD_ISEDITABLE,    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *VfasVmsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "PIDi",
        "Xi",
        "Ai",
        "Bi",
        "Ci1",
        "T1",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int VfasVmsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'P' && strcmp(fieldName, "PIDi") == 0) return base+0;
    if (fieldName[0] == 'X' && strcmp(fieldName, "Xi") == 0) return base+1;
    if (fieldName[0] == 'A' && strcmp(fieldName, "Ai") == 0) return base+2;
    if (fieldName[0] == 'B' && strcmp(fieldName, "Bi") == 0) return base+3;
    if (fieldName[0] == 'C' && strcmp(fieldName, "Ci1") == 0) return base+4;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T1") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *VfasVmsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_PIDi
        "int",    // FIELD_Xi
        "int",    // FIELD_Ai
        "int",    // FIELD_Bi
        "int",    // FIELD_Ci1
        "omnetpp::simtime_t",    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **VfasVmsgDescriptor::getFieldPropertyNames(int field) const
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

const char *VfasVmsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int VfasVmsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    VfasVmsg *pp = (VfasVmsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *VfasVmsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VfasVmsg *pp = (VfasVmsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VfasVmsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VfasVmsg *pp = (VfasVmsg *)object; (void)pp;
    switch (field) {
        case FIELD_PIDi: return long2string(pp->getPIDi());
        case FIELD_Xi: return long2string(pp->getXi());
        case FIELD_Ai: return long2string(pp->getAi());
        case FIELD_Bi: return long2string(pp->getBi());
        case FIELD_Ci1: return long2string(pp->getCi1());
        case FIELD_T1: return simtime2string(pp->getT1());
        default: return "";
    }
}

bool VfasVmsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    VfasVmsg *pp = (VfasVmsg *)object; (void)pp;
    switch (field) {
        case FIELD_PIDi: pp->setPIDi(string2long(value)); return true;
        case FIELD_Xi: pp->setXi(string2long(value)); return true;
        case FIELD_Ai: pp->setAi(string2long(value)); return true;
        case FIELD_Bi: pp->setBi(string2long(value)); return true;
        case FIELD_Ci1: pp->setCi1(string2long(value)); return true;
        case FIELD_T1: pp->setT1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *VfasVmsgDescriptor::getFieldStructName(int field) const
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

void *VfasVmsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    VfasVmsg *pp = (VfasVmsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(VfasRMsg)

VfasRMsg::VfasRMsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

VfasRMsg::VfasRMsg(const VfasRMsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

VfasRMsg::~VfasRMsg()
{
}

VfasRMsg& VfasRMsg::operator=(const VfasRMsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void VfasRMsg::copy(const VfasRMsg& other)
{
    this->IDfj = other.IDfj;
    this->PIDi = other.PIDi;
    this->Yj = other.Yj;
    this->Dj = other.Dj;
    this->Cj1 = other.Cj1;
    this->Tj1 = other.Tj1;
}

void VfasRMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->IDfj);
    doParsimPacking(b,this->PIDi);
    doParsimPacking(b,this->Yj);
    doParsimPacking(b,this->Dj);
    doParsimPacking(b,this->Cj1);
    doParsimPacking(b,this->Tj1);
}

void VfasRMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->IDfj);
    doParsimUnpacking(b,this->PIDi);
    doParsimUnpacking(b,this->Yj);
    doParsimUnpacking(b,this->Dj);
    doParsimUnpacking(b,this->Cj1);
    doParsimUnpacking(b,this->Tj1);
}

int VfasRMsg::getIDfj() const
{
    return this->IDfj;
}

void VfasRMsg::setIDfj(int IDfj)
{
    this->IDfj = IDfj;
}

int VfasRMsg::getPIDi() const
{
    return this->PIDi;
}

void VfasRMsg::setPIDi(int PIDi)
{
    this->PIDi = PIDi;
}

int VfasRMsg::getYj() const
{
    return this->Yj;
}

void VfasRMsg::setYj(int Yj)
{
    this->Yj = Yj;
}

int VfasRMsg::getDj() const
{
    return this->Dj;
}

void VfasRMsg::setDj(int Dj)
{
    this->Dj = Dj;
}

int VfasRMsg::getCj1() const
{
    return this->Cj1;
}

void VfasRMsg::setCj1(int Cj1)
{
    this->Cj1 = Cj1;
}

omnetpp::simtime_t VfasRMsg::getTj1() const
{
    return this->Tj1;
}

void VfasRMsg::setTj1(omnetpp::simtime_t Tj1)
{
    this->Tj1 = Tj1;
}

class VfasRMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_IDfj,
        FIELD_PIDi,
        FIELD_Yj,
        FIELD_Dj,
        FIELD_Cj1,
        FIELD_Tj1,
    };
  public:
    VfasRMsgDescriptor();
    virtual ~VfasRMsgDescriptor();

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

Register_ClassDescriptor(VfasRMsgDescriptor)

VfasRMsgDescriptor::VfasRMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::VfasRMsg)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

VfasRMsgDescriptor::~VfasRMsgDescriptor()
{
    delete[] propertynames;
}

bool VfasRMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VfasRMsg *>(obj)!=nullptr;
}

const char **VfasRMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *VfasRMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int VfasRMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int VfasRMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_IDfj
        FD_ISEDITABLE,    // FIELD_PIDi
        FD_ISEDITABLE,    // FIELD_Yj
        FD_ISEDITABLE,    // FIELD_Dj
        FD_ISEDITABLE,    // FIELD_Cj1
        FD_ISEDITABLE,    // FIELD_Tj1
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *VfasRMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "IDfj",
        "PIDi",
        "Yj",
        "Dj",
        "Cj1",
        "Tj1",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int VfasRMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDfj") == 0) return base+0;
    if (fieldName[0] == 'P' && strcmp(fieldName, "PIDi") == 0) return base+1;
    if (fieldName[0] == 'Y' && strcmp(fieldName, "Yj") == 0) return base+2;
    if (fieldName[0] == 'D' && strcmp(fieldName, "Dj") == 0) return base+3;
    if (fieldName[0] == 'C' && strcmp(fieldName, "Cj1") == 0) return base+4;
    if (fieldName[0] == 'T' && strcmp(fieldName, "Tj1") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *VfasRMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_IDfj
        "int",    // FIELD_PIDi
        "int",    // FIELD_Yj
        "int",    // FIELD_Dj
        "int",    // FIELD_Cj1
        "omnetpp::simtime_t",    // FIELD_Tj1
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **VfasRMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *VfasRMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int VfasRMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    VfasRMsg *pp = (VfasRMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *VfasRMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VfasRMsg *pp = (VfasRMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VfasRMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VfasRMsg *pp = (VfasRMsg *)object; (void)pp;
    switch (field) {
        case FIELD_IDfj: return long2string(pp->getIDfj());
        case FIELD_PIDi: return long2string(pp->getPIDi());
        case FIELD_Yj: return long2string(pp->getYj());
        case FIELD_Dj: return long2string(pp->getDj());
        case FIELD_Cj1: return long2string(pp->getCj1());
        case FIELD_Tj1: return simtime2string(pp->getTj1());
        default: return "";
    }
}

bool VfasRMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    VfasRMsg *pp = (VfasRMsg *)object; (void)pp;
    switch (field) {
        case FIELD_IDfj: pp->setIDfj(string2long(value)); return true;
        case FIELD_PIDi: pp->setPIDi(string2long(value)); return true;
        case FIELD_Yj: pp->setYj(string2long(value)); return true;
        case FIELD_Dj: pp->setDj(string2long(value)); return true;
        case FIELD_Cj1: pp->setCj1(string2long(value)); return true;
        case FIELD_Tj1: pp->setTj1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *VfasRMsgDescriptor::getFieldStructName(int field) const
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

void *VfasRMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    VfasRMsg *pp = (VfasRMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

