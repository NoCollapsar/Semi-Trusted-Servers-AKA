//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/Xie.msg.
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
#include "Xie_m.h"

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

Register_Class(VMessage)

VMessage::VMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

VMessage::VMessage(const VMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

VMessage::~VMessage()
{
}

VMessage& VMessage::operator=(const VMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void VMessage::copy(const VMessage& other)
{
    this->Dvi = other.Dvi;
    this->Cvi1 = other.Cvi1;
    this->Cvi2 = other.Cvi2;
    this->Cvi3 = other.Cvi3;
    this->T1 = other.T1;
}

void VMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->Dvi);
    doParsimPacking(b,this->Cvi1);
    doParsimPacking(b,this->Cvi2);
    doParsimPacking(b,this->Cvi3);
    doParsimPacking(b,this->T1);
}

void VMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->Dvi);
    doParsimUnpacking(b,this->Cvi1);
    doParsimUnpacking(b,this->Cvi2);
    doParsimUnpacking(b,this->Cvi3);
    doParsimUnpacking(b,this->T1);
}

int VMessage::getDvi() const
{
    return this->Dvi;
}

void VMessage::setDvi(int Dvi)
{
    this->Dvi = Dvi;
}

int VMessage::getCvi1() const
{
    return this->Cvi1;
}

void VMessage::setCvi1(int Cvi1)
{
    this->Cvi1 = Cvi1;
}

int VMessage::getCvi2() const
{
    return this->Cvi2;
}

void VMessage::setCvi2(int Cvi2)
{
    this->Cvi2 = Cvi2;
}

int VMessage::getCvi3() const
{
    return this->Cvi3;
}

void VMessage::setCvi3(int Cvi3)
{
    this->Cvi3 = Cvi3;
}

omnetpp::simtime_t VMessage::getT1() const
{
    return this->T1;
}

void VMessage::setT1(omnetpp::simtime_t T1)
{
    this->T1 = T1;
}

class VMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_Dvi,
        FIELD_Cvi1,
        FIELD_Cvi2,
        FIELD_Cvi3,
        FIELD_T1,
    };
  public:
    VMessageDescriptor();
    virtual ~VMessageDescriptor();

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

Register_ClassDescriptor(VMessageDescriptor)

VMessageDescriptor::VMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::VMessage)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

VMessageDescriptor::~VMessageDescriptor()
{
    delete[] propertynames;
}

bool VMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VMessage *>(obj)!=nullptr;
}

const char **VMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *VMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int VMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int VMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_Dvi
        FD_ISEDITABLE,    // FIELD_Cvi1
        FD_ISEDITABLE,    // FIELD_Cvi2
        FD_ISEDITABLE,    // FIELD_Cvi3
        FD_ISEDITABLE,    // FIELD_T1
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *VMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "Dvi",
        "Cvi1",
        "Cvi2",
        "Cvi3",
        "T1",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int VMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'D' && strcmp(fieldName, "Dvi") == 0) return base+0;
    if (fieldName[0] == 'C' && strcmp(fieldName, "Cvi1") == 0) return base+1;
    if (fieldName[0] == 'C' && strcmp(fieldName, "Cvi2") == 0) return base+2;
    if (fieldName[0] == 'C' && strcmp(fieldName, "Cvi3") == 0) return base+3;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T1") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *VMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_Dvi
        "int",    // FIELD_Cvi1
        "int",    // FIELD_Cvi2
        "int",    // FIELD_Cvi3
        "omnetpp::simtime_t",    // FIELD_T1
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **VMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *VMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int VMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    VMessage *pp = (VMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *VMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VMessage *pp = (VMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    VMessage *pp = (VMessage *)object; (void)pp;
    switch (field) {
        case FIELD_Dvi: return long2string(pp->getDvi());
        case FIELD_Cvi1: return long2string(pp->getCvi1());
        case FIELD_Cvi2: return long2string(pp->getCvi2());
        case FIELD_Cvi3: return long2string(pp->getCvi3());
        case FIELD_T1: return simtime2string(pp->getT1());
        default: return "";
    }
}

bool VMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    VMessage *pp = (VMessage *)object; (void)pp;
    switch (field) {
        case FIELD_Dvi: pp->setDvi(string2long(value)); return true;
        case FIELD_Cvi1: pp->setCvi1(string2long(value)); return true;
        case FIELD_Cvi2: pp->setCvi2(string2long(value)); return true;
        case FIELD_Cvi3: pp->setCvi3(string2long(value)); return true;
        case FIELD_T1: pp->setT1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *VMessageDescriptor::getFieldStructName(int field) const
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

void *VMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    VMessage *pp = (VMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RMessage)

RMessage::RMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

RMessage::RMessage(const RMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

RMessage::~RMessage()
{
}

RMessage& RMessage::operator=(const RMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void RMessage::copy(const RMessage& other)
{
    this->TVNi = other.TVNi;
    this->IDRi = other.IDRi;
    this->CRi1 = other.CRi1;
    this->Rvi = other.Rvi;
    this->T2 = other.T2;
}

void RMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->TVNi);
    doParsimPacking(b,this->IDRi);
    doParsimPacking(b,this->CRi1);
    doParsimPacking(b,this->Rvi);
    doParsimPacking(b,this->T2);
}

void RMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->TVNi);
    doParsimUnpacking(b,this->IDRi);
    doParsimUnpacking(b,this->CRi1);
    doParsimUnpacking(b,this->Rvi);
    doParsimUnpacking(b,this->T2);
}

int RMessage::getTVNi() const
{
    return this->TVNi;
}

void RMessage::setTVNi(int TVNi)
{
    this->TVNi = TVNi;
}

int RMessage::getIDRi() const
{
    return this->IDRi;
}

void RMessage::setIDRi(int IDRi)
{
    this->IDRi = IDRi;
}

int RMessage::getCRi1() const
{
    return this->CRi1;
}

void RMessage::setCRi1(int CRi1)
{
    this->CRi1 = CRi1;
}

int RMessage::getRvi() const
{
    return this->Rvi;
}

void RMessage::setRvi(int Rvi)
{
    this->Rvi = Rvi;
}

omnetpp::simtime_t RMessage::getT2() const
{
    return this->T2;
}

void RMessage::setT2(omnetpp::simtime_t T2)
{
    this->T2 = T2;
}

class RMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_TVNi,
        FIELD_IDRi,
        FIELD_CRi1,
        FIELD_Rvi,
        FIELD_T2,
    };
  public:
    RMessageDescriptor();
    virtual ~RMessageDescriptor();

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

Register_ClassDescriptor(RMessageDescriptor)

RMessageDescriptor::RMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::RMessage)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

RMessageDescriptor::~RMessageDescriptor()
{
    delete[] propertynames;
}

bool RMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RMessage *>(obj)!=nullptr;
}

const char **RMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_TVNi
        FD_ISEDITABLE,    // FIELD_IDRi
        FD_ISEDITABLE,    // FIELD_CRi1
        FD_ISEDITABLE,    // FIELD_Rvi
        FD_ISEDITABLE,    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *RMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "TVNi",
        "IDRi",
        "CRi1",
        "Rvi",
        "T2",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int RMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'T' && strcmp(fieldName, "TVNi") == 0) return base+0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDRi") == 0) return base+1;
    if (fieldName[0] == 'C' && strcmp(fieldName, "CRi1") == 0) return base+2;
    if (fieldName[0] == 'R' && strcmp(fieldName, "Rvi") == 0) return base+3;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T2") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_TVNi
        "int",    // FIELD_IDRi
        "int",    // FIELD_CRi1
        "int",    // FIELD_Rvi
        "omnetpp::simtime_t",    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **RMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *RMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RMessage *pp = (RMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RMessage *pp = (RMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RMessage *pp = (RMessage *)object; (void)pp;
    switch (field) {
        case FIELD_TVNi: return long2string(pp->getTVNi());
        case FIELD_IDRi: return long2string(pp->getIDRi());
        case FIELD_CRi1: return long2string(pp->getCRi1());
        case FIELD_Rvi: return long2string(pp->getRvi());
        case FIELD_T2: return simtime2string(pp->getT2());
        default: return "";
    }
}

bool RMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RMessage *pp = (RMessage *)object; (void)pp;
    switch (field) {
        case FIELD_TVNi: pp->setTVNi(string2long(value)); return true;
        case FIELD_IDRi: pp->setIDRi(string2long(value)); return true;
        case FIELD_CRi1: pp->setCRi1(string2long(value)); return true;
        case FIELD_Rvi: pp->setRvi(string2long(value)); return true;
        case FIELD_T2: pp->setT2(string2simtime(value)); return true;
        default: return false;
    }
}

const char *RMessageDescriptor::getFieldStructName(int field) const
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

void *RMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RMessage *pp = (RMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RBroad)

RBroad::RBroad(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

RBroad::RBroad(const RBroad& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

RBroad::~RBroad()
{
}

RBroad& RBroad::operator=(const RBroad& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void RBroad::copy(const RBroad& other)
{
    this->IDRi = other.IDRi;
    this->XRi = other.XRi;
    this->CRi = other.CRi;
    this->ARi = other.ARi;
}

void RBroad::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->IDRi);
    doParsimPacking(b,this->XRi);
    doParsimPacking(b,this->CRi);
    doParsimPacking(b,this->ARi);
}

void RBroad::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->IDRi);
    doParsimUnpacking(b,this->XRi);
    doParsimUnpacking(b,this->CRi);
    doParsimUnpacking(b,this->ARi);
}

int RBroad::getIDRi() const
{
    return this->IDRi;
}

void RBroad::setIDRi(int IDRi)
{
    this->IDRi = IDRi;
}

int RBroad::getXRi() const
{
    return this->XRi;
}

void RBroad::setXRi(int XRi)
{
    this->XRi = XRi;
}

int RBroad::getCRi() const
{
    return this->CRi;
}

void RBroad::setCRi(int CRi)
{
    this->CRi = CRi;
}

int RBroad::getARi() const
{
    return this->ARi;
}

void RBroad::setARi(int ARi)
{
    this->ARi = ARi;
}

class RBroadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_IDRi,
        FIELD_XRi,
        FIELD_CRi,
        FIELD_ARi,
    };
  public:
    RBroadDescriptor();
    virtual ~RBroadDescriptor();

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

Register_ClassDescriptor(RBroadDescriptor)

RBroadDescriptor::RBroadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::RBroad)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

RBroadDescriptor::~RBroadDescriptor()
{
    delete[] propertynames;
}

bool RBroadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RBroad *>(obj)!=nullptr;
}

const char **RBroadDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RBroadDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RBroadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int RBroadDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_IDRi
        FD_ISEDITABLE,    // FIELD_XRi
        FD_ISEDITABLE,    // FIELD_CRi
        FD_ISEDITABLE,    // FIELD_ARi
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *RBroadDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "IDRi",
        "XRi",
        "CRi",
        "ARi",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int RBroadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'I' && strcmp(fieldName, "IDRi") == 0) return base+0;
    if (fieldName[0] == 'X' && strcmp(fieldName, "XRi") == 0) return base+1;
    if (fieldName[0] == 'C' && strcmp(fieldName, "CRi") == 0) return base+2;
    if (fieldName[0] == 'A' && strcmp(fieldName, "ARi") == 0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RBroadDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_IDRi
        "int",    // FIELD_XRi
        "int",    // FIELD_CRi
        "int",    // FIELD_ARi
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **RBroadDescriptor::getFieldPropertyNames(int field) const
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

const char *RBroadDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RBroadDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RBroad *pp = (RBroad *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RBroadDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RBroad *pp = (RBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RBroadDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RBroad *pp = (RBroad *)object; (void)pp;
    switch (field) {
        case FIELD_IDRi: return long2string(pp->getIDRi());
        case FIELD_XRi: return long2string(pp->getXRi());
        case FIELD_CRi: return long2string(pp->getCRi());
        case FIELD_ARi: return long2string(pp->getARi());
        default: return "";
    }
}

bool RBroadDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RBroad *pp = (RBroad *)object; (void)pp;
    switch (field) {
        case FIELD_IDRi: pp->setIDRi(string2long(value)); return true;
        case FIELD_XRi: pp->setXRi(string2long(value)); return true;
        case FIELD_CRi: pp->setCRi(string2long(value)); return true;
        case FIELD_ARi: pp->setARi(string2long(value)); return true;
        default: return false;
    }
}

const char *RBroadDescriptor::getFieldStructName(int field) const
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

void *RBroadDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RBroad *pp = (RBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

