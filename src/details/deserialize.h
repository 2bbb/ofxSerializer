BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

#pragma mark Deserialize

// deserializable object
template <typename T>
type_filter(has_deserialize<T>) deserialize(std::istream &is, T &v) {
    v.deserialize(is);
}

// number
template <typename T>
type_filter(is_number<T>) deserialize(std::istream &is, T &v) {
    is.read((char *)(&v), sizeof(T));
}

// object
template <typename T>
type_filter(is_object<T, has_deserialize>) deserialize(std::istream &is, T &v) {
    is.read((char *)(&v), sizeof(T));
}

// string
inline void deserialize(std::istream &is, std::string &v) {
    size_t length;
    deserialize(is, length);
    v.resize(length - 1);
    
    is.read((char *)(v.data()), length);
}

// pointer
template <typename T>
type_filter(is_pointer_without_array<T>) deserialize(std::istream &is, T &v) {
    bool b;
    deserialize(is, b);
    if(b) deserialize(is, *(v ?: (v = new typename util::remove_pointer<T>::type)));
        }

// shared_ptr
template <typename T>
inline void deserialize(std::istream &is, shared_ptr<T> &v) {
    bool b;
    deserialize(is, b);
    if(b) deserialize(is, *((v ? v : (v = shared_ptr<T>(new T)))->get()));
}

// array
template <typename T>
type_filter(is_array<T>) deserialize(std::istream &is, T &v) {
    for(size_t i = 0; i < util::length(v); i++) {
        deserialize(is, v[i]);
    }
}

// container of number
template <typename T, typename Alloc, template<typename, typename> class Container>
type_filter(is_number<T>) deserialize(std::istream &is, Container<T, Alloc> &v) {
    size_t size;
    deserialize(is, size);
    v.resize(size);
    
    is.read((char *)(&v[0]), sizeof(T) * size);
}

// container of object
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<!util::is_arithmetic<T>::value>::type
deserialize(std::istream &is, Container<T, Alloc> &v) {
    size_t size;
    deserialize(is, size);
    v.resize(size);
    
    for(size_t i = 0; i < v.size(); i++) deserialize(is, v[i]);
}

// deserialize body
#if 0
// for C++11
template <typename Arg, typename ... Args>
inline void deserialize(std::istream &is, Arg &arg, Args& ... args) {
    deserialize(is, arg);
    deserialize(is, args ...);
}
#else
#include "deserialize_oldcpp.h"
#endif

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)
