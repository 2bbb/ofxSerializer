//
//  ofxSerializer.h
//
//  Created by ISHII 2bit on 2015/04/28.
//
//

#pragma once

#include "ofMain.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE(name) };

#include "details/utils.h"

BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)
namespace {
    template <typename T>
    struct has_serialize_impl {
    private:
        template <typename U>
        static char check_method(typeof(&U::serialize));
        template <typename>
        static long check_method(...);
    public:
        static const bool value = (sizeof(check_method<T>(0)) == sizeof(char));
    };
    
    template <typename T>
    struct has_deserialize_impl {
    private:
        template <typename U>
        static char check_method(typeof(&U::deserialize));
        template <typename>
        static long check_method(...);
    public:
        static const bool value = (sizeof(check_method<T>(0)) == sizeof(char));
    };

    template <typename T>
    struct has_jsonize_impl {
    private:
        template <typename U>
        static char check_method(typeof(&U::jsonize));
        template <typename>
        static long check_method(...);
    public:
        static const bool value = (sizeof(check_method<T>(0)) == sizeof(char));
    };

#if 0
#pragma mark after C++11
    template <typename T>
    using has_serialize = typename util::enable_if<has_serialize_impl<T>::value>::type;
    template <typename T>
    using not_has_serialize = typename util::enable_if<!has_serialize_impl<T>::value>::type;
    
    template <typename T>
    using has_deserialize = typename util::enable_if<has_deserialize_impl<T>::value>::type;
    template <typename T>
    using not_has_deserialize = typename util::enable_if<!has_deserialize_impl<T>::value>::type;
#endif
};

#pragma mark Deserialize

// serializable object
template <typename T>
inline typename util::enable_if<has_serialize_impl<T>::value>::type
serialize(std::ostream &os, const T &v) {
    v.serialize(os);
}

// number
template <typename T>
inline typename util::enable_if<util::is_arithmetic<T>::value>::type
serialize(std::ostream &os, T v) {
    os.write((char *)(&v), sizeof(T));
}

// object
template <typename T>
inline typename util::enable_if<!util::is_arithmetic<T>::value && !has_serialize_impl<T>::value>::type
serialize(std::ostream &os, const T &v) {
    os.write((char *)(&v), sizeof(T));
}

// string
inline void serialize(std::ostream &os, const std::string &v) {
    serialize(os, v.length() + 1);
    os.write(v.c_str(), v.length() + 1);
}

// container of number
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<util::is_arithmetic<T>::value>::type serialize(std::ostream &os, const Container<T, Alloc> &v) {
    serialize(os, v.size());
    os.write((char *)(&v[0]), sizeof(T) * v.size());
}

// container of object
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<!util::is_arithmetic<T>::value>::type serialize(std::ostream &os, const Container<T, Alloc> &v) {
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
#include "details/serialize.h"
#endif

#pragma mark Deserialize

// deserializable object
template <typename T>
inline typename util::enable_if<has_deserialize_impl<T>::value>::type deserialize(std::istream &is, T &v) {
    v.deserialize(is);
}

// number
template <typename T>
inline typename util::enable_if<util::is_arithmetic<T>::value>::type
deserialize(std::istream &is, T &v) {
    is.read((char *)(&v), sizeof(T));
}

// object
template <typename T>
inline typename util::enable_if<!util::is_arithmetic<T>::value && !has_deserialize_impl<T>::value>::type
deserialize(std::istream &is, T &v) {
    is.read((char *)(&v), sizeof(T));
}

// string
inline void deserialize(std::istream &is, std::string &v) {
    size_t length;
    deserialize(is, length);
    v.resize(length);
    
    is.read((char *)(v.data()), length);
}


// container of number
template <typename T, typename Alloc, template<typename, typename> class Container>
inline typename util::enable_if<util::is_arithmetic<T>::value>::type
deserialize(std::istream &is, Container<T, Alloc> &v) {
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
#include "details/deserialize.h"
#endif

#pragma mark Jsonizer

inline std::ostream &json_key(std::ostream &os, const char * const key) {
    os << "\"" << key << "\": ";
    return os;
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
    json_key(os, key) << "{";
    v.jsonize(os);
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
template <typename Arg1, typename Arg2, typename ... Args>
inline void jsonize(std::ostream &os, const char * const key, const Arg1 &v, const char * const key2, const Arg2 &v2, const Args & ... args) {
    jsonize(os, key1, v1);
    jsonize(os << ", ", key2, v2, args ...);
};
#else
#include "details/jsonize.h"
#endif

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)

#undef BEGIN_NAMESPACE
#undef END_NAMESPACE

#pragma mark main

namespace ofxSerializer = ofx::Serializer;

#define DefineSerializeMethod(...) \
inline void serialize(std::ostream &os) const { \
    ofxSerializer::serialize(os, __VA_ARGS__); \
}; \
inline void deserialize(std::istream &is) { \
    ofxSerializer::deserialize(is, __VA_ARGS__); \
};

#define DefineSerializeFunction(Type, name, ...) \
namespace ofx { \
    namespace Serializer { \
        inline void serialize(std::ostream &os, const Type &name) { \
            serialize(os, __VA_ARGS__); \
        }; \
        inline void deserialize(std::istream &is, Type &name) { \
            deserialize(is, __VA_ARGS__); \
        }; \
    }; \
};

#define Super(Type, This) \
static_cast<Type &>( \
    const_cast< \
        util::add_lvalue_reference< \
            util::remove_const< \
                util::remove_pointer< \
                    const This * \
                >::type \
            >::type \
        >::type \
    >(*this) \
)

#include "details/jsonize_macros.h"

#define DefineJsonizeMethod(...) \
inline void jsonize(std::ostream &os) const { \
    os << "{"; \
    ofxSerializer::jsonize(os, MakeStringifiedPair(__VA_ARGS__)); \
    os << "}"; \
};

DefineSerializeFunction(ofVec2f, p, p.x, p.y);
DefineSerializeFunction(ofVec3f, p, p.x, p.y, p.z);
DefineSerializeFunction(ofVec4f, p, p.x, p.y, p.z, p.w);
DefineSerializeFunction(ofColor, c, c.r, c.g, c.b, c.a);
DefineSerializeFunction(ofRectangle, rect, rect.x, rect.y, rect.width, rect.height);
