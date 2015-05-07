BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

#define SimpleDebugLog(tag, text) ;
//#define SimpleDebugLog(tag, text) ofLogNotice(tag) << text;

// serializable object
template <typename T>
type_filter(has_serialize<T>) serialize(std::ostream &os, const T &v) {
    SimpleDebugLog("debug/serialize", "serializable");
    v.serialize(os);
}

// number
template <typename T>
type_filter(is_number<T>) serialize(std::ostream &os, T v) {
    SimpleDebugLog("debug/serialize", "number " << v);
    os.write((char *)(&v), sizeof(T));
}

// object
template <typename T>
type_filter(is_object<T, has_serialize>) serialize(std::ostream &os, const T &v) {
    SimpleDebugLog("debug/serialize", "object");
    os.write((char *)(&v), sizeof(T));
}

// string
inline void serialize(std::ostream &os, const std::string &v) {
    SimpleDebugLog("debug/serialize", "string");
    serialize(os, v.length() + 1);
    os.write(v.c_str(), v.length() + 1);
}

// pointer
template <typename T>
type_filter(is_pointer_without_array<T>) serialize(std::ostream &os, const T &v) {
    SimpleDebugLog("debug/serialize", "pointer " << v);
    serialize(os, static_cast<bool>(v != NULL));
    if(static_cast<bool>(v != NULL)) serialize(os, *v);
        }

// shared_ptr
template <typename T>
inline void serialize(std::ostream &os, shared_ptr<T> &v) {
    SimpleDebugLog("debug/serialize", "shared_ptr");
    serialize(os, static_cast<bool>(v));
    if(static_cast<bool>(v)) serialize(os, *(v->get()));
}

// array
template <typename T>
type_filter(is_array<T>) serialize(std::ostream &os, T &v) {
    SimpleDebugLog("debug/serialize", "array " << util::length(v) << endl);
    for(size_t i = 0; i < util::length(v); i++) serialize(os, v[i]);
        }

// container of number
template <typename T, typename Alloc, template<typename, typename> class Container>
type_filter(is_number<T>) serialize(std::ostream &os, const Container<T, Alloc> &v) {
    SimpleDebugLog("debug/serialize", "container of number");
    serialize(os, v.size());
    os.write((char *)(&v[0]), sizeof(T) * v.size());
}

// container of object
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<!util::is_arithmetic<T>::value && !util::is_pointer<T>::value>::type serialize(std::ostream &os, const Container<T, Alloc> &v) {
    SimpleDebugLog("debug/serialize", "container of object");
    serialize(os, v.size());
    for(size_t i = 0; i < v.size(); i++) serialize(os, v[i]);
}

// serialize body
#if 0
template <typename Arg, typename ... Args>
inline void serialize(std::ostream &os, const Arg &arg, const Args& ... args) {
    serialize(os, arg);
    serialize(os, args ...);
}
#else
#include "serialize_oldcpp.h"
#endif

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)
