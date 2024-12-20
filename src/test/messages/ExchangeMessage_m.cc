//
// Generated file, do not edit! Created by nedtool 5.7 from veins/test/messages/ExchangeMessage.msg.
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
#include "ExchangeMessage_m.h"

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

Register_Class(M1Message)

M1Message::M1Message(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

M1Message::M1Message(const M1Message& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

M1Message::~M1Message()
{
}

M1Message& M1Message::operator=(const M1Message& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void M1Message::copy(const M1Message& other)
{
    this->VID = other.VID;
    this->ri = other.ri;
    this->W1 = other.W1;
    this->W2 = other.W2;
    this->sd = other.sd;
    this->T1 = other.T1;
}

void M1Message::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->VID);
    doParsimPacking(b,this->ri);
    doParsimPacking(b,this->W1);
    doParsimPacking(b,this->W2);
    doParsimPacking(b,this->sd);
    doParsimPacking(b,this->T1);
}

void M1Message::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->VID);
    doParsimUnpacking(b,this->ri);
    doParsimUnpacking(b,this->W1);
    doParsimUnpacking(b,this->W2);
    doParsimUnpacking(b,this->sd);
    doParsimUnpacking(b,this->T1);
}

int M1Message::getVID() const
{
    return this->VID;
}

void M1Message::setVID(int VID)
{
    this->VID = VID;
}

int M1Message::getRi() const
{
    return this->ri;
}

void M1Message::setRi(int ri)
{
    this->ri = ri;
}

int M1Message::getW1() const
{
    return this->W1;
}

void M1Message::setW1(int W1)
{
    this->W1 = W1;
}

int M1Message::getW2() const
{
    return this->W2;
}

void M1Message::setW2(int W2)
{
    this->W2 = W2;
}

int M1Message::getSd() const
{
    return this->sd;
}

void M1Message::setSd(int sd)
{
    this->sd = sd;
}

omnetpp::simtime_t M1Message::getT1() const
{
    return this->T1;
}

void M1Message::setT1(omnetpp::simtime_t T1)
{
    this->T1 = T1;
}

class M1MessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_VID,
        FIELD_ri,
        FIELD_W1,
        FIELD_W2,
        FIELD_sd,
        FIELD_T1,
    };
  public:
    M1MessageDescriptor();
    virtual ~M1MessageDescriptor();

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

Register_ClassDescriptor(M1MessageDescriptor)

M1MessageDescriptor::M1MessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::M1Message)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

M1MessageDescriptor::~M1MessageDescriptor()
{
    delete[] propertynames;
}

bool M1MessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<M1Message *>(obj)!=nullptr;
}

const char **M1MessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *M1MessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int M1MessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int M1MessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_VID
        FD_ISEDITABLE,    // FIELD_ri
        FD_ISEDITABLE,    // FIELD_W1
        FD_ISEDITABLE,    // FIELD_W2
        FD_ISEDITABLE,    // FIELD_sd
        FD_ISEDITABLE,    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *M1MessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "VID",
        "ri",
        "W1",
        "W2",
        "sd",
        "T1",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int M1MessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'V' && strcmp(fieldName, "VID") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "ri") == 0) return base+1;
    if (fieldName[0] == 'W' && strcmp(fieldName, "W1") == 0) return base+2;
    if (fieldName[0] == 'W' && strcmp(fieldName, "W2") == 0) return base+3;
    if (fieldName[0] == 's' && strcmp(fieldName, "sd") == 0) return base+4;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T1") == 0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *M1MessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_VID
        "int",    // FIELD_ri
        "int",    // FIELD_W1
        "int",    // FIELD_W2
        "int",    // FIELD_sd
        "omnetpp::simtime_t",    // FIELD_T1
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **M1MessageDescriptor::getFieldPropertyNames(int field) const
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

const char *M1MessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int M1MessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    M1Message *pp = (M1Message *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *M1MessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    M1Message *pp = (M1Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string M1MessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    M1Message *pp = (M1Message *)object; (void)pp;
    switch (field) {
        case FIELD_VID: return long2string(pp->getVID());
        case FIELD_ri: return long2string(pp->getRi());
        case FIELD_W1: return long2string(pp->getW1());
        case FIELD_W2: return long2string(pp->getW2());
        case FIELD_sd: return long2string(pp->getSd());
        case FIELD_T1: return simtime2string(pp->getT1());
        default: return "";
    }
}

bool M1MessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    M1Message *pp = (M1Message *)object; (void)pp;
    switch (field) {
        case FIELD_VID: pp->setVID(string2long(value)); return true;
        case FIELD_ri: pp->setRi(string2long(value)); return true;
        case FIELD_W1: pp->setW1(string2long(value)); return true;
        case FIELD_W2: pp->setW2(string2long(value)); return true;
        case FIELD_sd: pp->setSd(string2long(value)); return true;
        case FIELD_T1: pp->setT1(string2simtime(value)); return true;
        default: return false;
    }
}

const char *M1MessageDescriptor::getFieldStructName(int field) const
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

void *M1MessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    M1Message *pp = (M1Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(M2Message)

M2Message::M2Message(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

M2Message::M2Message(const M2Message& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

M2Message::~M2Message()
{
}

M2Message& M2Message::operator=(const M2Message& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void M2Message::copy(const M2Message& other)
{
    this->RID = other.RID;
    this->rj = other.rj;
    this->W3 = other.W3;
    this->sd = other.sd;
    this->T2 = other.T2;
}

void M2Message::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->RID);
    doParsimPacking(b,this->rj);
    doParsimPacking(b,this->W3);
    doParsimPacking(b,this->sd);
    doParsimPacking(b,this->T2);
}

void M2Message::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->RID);
    doParsimUnpacking(b,this->rj);
    doParsimUnpacking(b,this->W3);
    doParsimUnpacking(b,this->sd);
    doParsimUnpacking(b,this->T2);
}

int M2Message::getRID() const
{
    return this->RID;
}

void M2Message::setRID(int RID)
{
    this->RID = RID;
}

int M2Message::getRj() const
{
    return this->rj;
}

void M2Message::setRj(int rj)
{
    this->rj = rj;
}

int M2Message::getW3() const
{
    return this->W3;
}

void M2Message::setW3(int W3)
{
    this->W3 = W3;
}

int M2Message::getSd() const
{
    return this->sd;
}

void M2Message::setSd(int sd)
{
    this->sd = sd;
}

omnetpp::simtime_t M2Message::getT2() const
{
    return this->T2;
}

void M2Message::setT2(omnetpp::simtime_t T2)
{
    this->T2 = T2;
}

class M2MessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_RID,
        FIELD_rj,
        FIELD_W3,
        FIELD_sd,
        FIELD_T2,
    };
  public:
    M2MessageDescriptor();
    virtual ~M2MessageDescriptor();

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

Register_ClassDescriptor(M2MessageDescriptor)

M2MessageDescriptor::M2MessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::M2Message)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

M2MessageDescriptor::~M2MessageDescriptor()
{
    delete[] propertynames;
}

bool M2MessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<M2Message *>(obj)!=nullptr;
}

const char **M2MessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *M2MessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int M2MessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int M2MessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_RID
        FD_ISEDITABLE,    // FIELD_rj
        FD_ISEDITABLE,    // FIELD_W3
        FD_ISEDITABLE,    // FIELD_sd
        FD_ISEDITABLE,    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *M2MessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "RID",
        "rj",
        "W3",
        "sd",
        "T2",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int M2MessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "RID") == 0) return base+0;
    if (fieldName[0] == 'r' && strcmp(fieldName, "rj") == 0) return base+1;
    if (fieldName[0] == 'W' && strcmp(fieldName, "W3") == 0) return base+2;
    if (fieldName[0] == 's' && strcmp(fieldName, "sd") == 0) return base+3;
    if (fieldName[0] == 'T' && strcmp(fieldName, "T2") == 0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *M2MessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_RID
        "int",    // FIELD_rj
        "int",    // FIELD_W3
        "int",    // FIELD_sd
        "omnetpp::simtime_t",    // FIELD_T2
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **M2MessageDescriptor::getFieldPropertyNames(int field) const
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

const char *M2MessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int M2MessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    M2Message *pp = (M2Message *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *M2MessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    M2Message *pp = (M2Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string M2MessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    M2Message *pp = (M2Message *)object; (void)pp;
    switch (field) {
        case FIELD_RID: return long2string(pp->getRID());
        case FIELD_rj: return long2string(pp->getRj());
        case FIELD_W3: return long2string(pp->getW3());
        case FIELD_sd: return long2string(pp->getSd());
        case FIELD_T2: return simtime2string(pp->getT2());
        default: return "";
    }
}

bool M2MessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    M2Message *pp = (M2Message *)object; (void)pp;
    switch (field) {
        case FIELD_RID: pp->setRID(string2long(value)); return true;
        case FIELD_rj: pp->setRj(string2long(value)); return true;
        case FIELD_W3: pp->setW3(string2long(value)); return true;
        case FIELD_sd: pp->setSd(string2long(value)); return true;
        case FIELD_T2: pp->setT2(string2simtime(value)); return true;
        default: return false;
    }
}

const char *M2MessageDescriptor::getFieldStructName(int field) const
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

void *M2MessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    M2Message *pp = (M2Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IDBroad)

IDBroad::IDBroad(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

IDBroad::IDBroad(const IDBroad& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

IDBroad::~IDBroad()
{
}

IDBroad& IDBroad::operator=(const IDBroad& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void IDBroad::copy(const IDBroad& other)
{
    this->R = other.R;
    this->Name = other.Name;
}

void IDBroad::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->R);
    doParsimPacking(b,this->Name);
}

void IDBroad::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->R);
    doParsimUnpacking(b,this->Name);
}

int IDBroad::getR() const
{
    return this->R;
}

void IDBroad::setR(int R)
{
    this->R = R;
}

const char * IDBroad::getName() const
{
    return this->Name.c_str();
}

void IDBroad::setName(const char * Name)
{
    this->Name = Name;
}

class IDBroadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
    enum FieldConstants {
        FIELD_R,
        FIELD_Name,
    };
  public:
    IDBroadDescriptor();
    virtual ~IDBroadDescriptor();

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

Register_ClassDescriptor(IDBroadDescriptor)

IDBroadDescriptor::IDBroadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::IDBroad)), "veins::BaseFrame1609_4")
{
    propertynames = nullptr;
}

IDBroadDescriptor::~IDBroadDescriptor()
{
    delete[] propertynames;
}

bool IDBroadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IDBroad *>(obj)!=nullptr;
}

const char **IDBroadDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IDBroadDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IDBroadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IDBroadDescriptor::getFieldTypeFlags(int field) const
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

const char *IDBroadDescriptor::getFieldName(int field) const
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

int IDBroadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0] == 'R' && strcmp(fieldName, "R") == 0) return base+0;
    if (fieldName[0] == 'N' && strcmp(fieldName, "Name") == 0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IDBroadDescriptor::getFieldTypeString(int field) const
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

const char **IDBroadDescriptor::getFieldPropertyNames(int field) const
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

const char *IDBroadDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IDBroadDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IDBroad *pp = (IDBroad *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IDBroadDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IDBroad *pp = (IDBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IDBroadDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IDBroad *pp = (IDBroad *)object; (void)pp;
    switch (field) {
        case FIELD_R: return long2string(pp->getR());
        case FIELD_Name: return oppstring2string(pp->getName());
        default: return "";
    }
}

bool IDBroadDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IDBroad *pp = (IDBroad *)object; (void)pp;
    switch (field) {
        case FIELD_R: pp->setR(string2long(value)); return true;
        case FIELD_Name: pp->setName((value)); return true;
        default: return false;
    }
}

const char *IDBroadDescriptor::getFieldStructName(int field) const
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

void *IDBroadDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IDBroad *pp = (IDBroad *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace veins

