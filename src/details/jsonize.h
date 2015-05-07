BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

#pragma mark Jsonizer

inline std::ostream &json_key(std::ostream &os, const char * const key) {
    return os << "\"" << key << "\": ";
}

// bool
inline void jsonize(std::ostream &os, const char * const key, bool v) {
    json_key(os, key) << (v ? "true" : "false");
};

// number
template <typename T>
inline typename util::enable_if<
util::is_arithmetic<T>::value && !util::is_same<T, bool>::value
>::type jsonize(std::ostream &os, const char * const key, T v) {
    json_key(os, key) << v;
};

// string
inline void jsonize(std::ostream &os, const char * const key, const std::string &v) {
    os << "\"" << key << "\": " << "\"" << v << "\"";
};

// jsonizable object
template <typename T>
inline typename util::enable_if<has_jsonize_impl<T>::value>::type jsonize(std::ostream &os, const char * const key, const T &v) {
    v.jsonize(json_key(os, key) << "{");
    os << "}";
};

// container of bool
template <typename Alloc, template<typename, typename> class Container>
inline void jsonize(std::ostream &os, const char * const key, const Container<bool, Alloc> &v) {
    json_key(os, key) << "[";
    for(size_t i = 0; i < v.size() - 1; i++) os << (v[i] ? "true" : "false") << ", ";
    os << (v[v.size() - 1] ? "true" : "false") << "]";
};

// container of number
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<util::is_arithmetic<T>::value>::type jsonize(std::ostream &os, const char * const key, const Container<T, Alloc> &v) {
    json_key(os, key) << "[";
    for(size_t i = 0; i < v.size() - 1; i++) os << v[i] << ", ";
    os << v[v.size() - 1]  << "]";
};

// container of string
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<!util::is_arithmetic<T>::value && util::is_same<T, std::string>::value>::type jsonize(std::ostream &os, const char * const key, const Container<T, Alloc> &v) {
    json_key(os, key) << "[";
    for(size_t i = 0; i < v.size() - 1; i++) os  << "\"" << v[i] << "\"" << ", ";
    os << "\"" << v[v.size() - 1] << "\"]";
};

// container of jsonizable object
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<has_jsonize_impl<T>::value>::type jsonize(std::ostream &os, const char * const key, const Container<T, Alloc> &v) {
    json_key(os, key) << "[";
    v[0].jsonize(os);
    for(size_t i = 1; i < v.size(); i++) v[i].jsonize(os << ", ");
    os << "]";
};

#if 0
template <typename Arg>
inline void jsonize(std::ostream &os, const char * const key, const Arg &v) {
    jsonize(os, key, v);
};
template <typename Arg1, typename ... Args>
inline void jsonize(std::ostream &os, const char * const key, const Arg1 &v, const Args & ... args) {
    jsonize(os, key1, v1);
    jsonize(os << ", ", args ...);
};
#else
#include "jsonize_oldcpp.h"
#endif

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)
