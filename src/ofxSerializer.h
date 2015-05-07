//
//  ofxSerializer.h
//
//  Created by ISHII 2bit on 2015/04/28.
//
//

#pragma once

#include "ofMain.h"

#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE(name) };

#include "details/utils.h"

#if (_MSC_VER)
#   define DECLTYPE(...) decltype(__VA_ARGS__)
#else
#   if __cplusplus<201103L
#       define DECLTYPE(...) typeof(__VA_ARGS__)
#   else
#       define DECLTYPE(...) decltype(__VA_ARGS__)
#   endif
#endif

BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)
namespace {
#define DefineMethodChecker(method) \
    template <typename T> \
    struct has_##method##_impl { \
    private: \
        template <typename U> \
        static char check_method(DECLTYPE(&U::method)); \
        template <typename> \
        static long check_method(...); \
    public: \
        static const bool value = (sizeof(check_method<T>(0)) == sizeof(char)); \
    };

    DefineMethodChecker(serialize); // define struct has_serialize_impl
    DefineMethodChecker(deserialize); // define struct has_deserialize_impl
    DefineMethodChecker(jsonize); // define struct has_jsonize_impl
#undef DefineMethodChecker
    
#pragma mark type_filter predicate
    template <typename T>
    struct has_serialize {
        static const bool value = has_serialize_impl<T>::value;
    };
    
    template <typename T>
    struct has_deserialize {
        static const bool value = has_deserialize_impl<T>::value;
    };
    
    template <typename T>
    struct is_number {
        static const bool value = util::is_arithmetic<T>::value;
    };
    
    template <typename T, template <typename> class Template>
    struct is_object {
        static const bool value = !util::is_arithmetic<T>::value
                               && !util::is_array<T>::value
                               && !util::is_pointer<T>::value
                               && !Template<T>::value;
    };
    
    template <typename T>
    struct is_pointer_without_array {
        static const bool value = !util::is_array<T>::value
                               && util::is_pointer<T>::value;
    };
    
    template <typename T>
    struct is_array {
        static const bool value = util::is_array<T>::value;
    };
};

#define type_filter(...) inline typename util::enable_if<__VA_ARGS__::value >::type

#pragma mark Deserialize

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
#include "details/serialize_oldcpp.h"
#endif

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
#include "details/deserialize_oldcpp.h"
#endif

#include "details/jsonize.h"

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)

#pragma mark main

namespace ofxSerializer = ofx::Serializer;

#define DefineSerializeMethod(...) \
inline void serialize(std::ostream &os) const { \
    ofxSerializer::serialize(os, __VA_ARGS__); \
}; \
inline void deserialize(std::istream &is) { \
    ofxSerializer::deserialize(is, __VA_ARGS__); \
}; \
inline void saveToFile(const std::string &filePath) const { \
    std::ofstream ofs; \
    ofs.open(ofToDataPath(filePath, true).c_str(), std::ios::out | std::ios::binary);\
    serialize(ofs);\
}; \
inline void loadFromFile(const std::string &filePath) { \
    std::ifstream ifs; \
    ifs.open(ofToDataPath(filePath, true).c_str(), std::ios::in);\
    deserialize(ifs);\
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

DefineSerializeFunction(ofMatrix3x3, mat, mat.a, mat.b, mat.c, mat.d, mat.e, mat.f, mat.g, mat.h, mat.i);
DefineSerializeFunction(ofMatrix4x4, mat, mat._mat);
DefineSerializeFunction(ofQuaternion, quat, quat._v)
DefineSerializeFunction(ofVec2f, p, p.x, p.y);
DefineSerializeFunction(ofVec3f, p, p.x, p.y, p.z);
DefineSerializeFunction(ofVec4f, p, p.x, p.y, p.z, p.w);
DefineSerializeFunction(ofColor, c, c.r, c.g, c.b, c.a);
DefineSerializeFunction(ofFloatColor, c, c.r, c.g, c.b, c.a);
DefineSerializeFunction(ofRectangle, rect, rect.x, rect.y, rect.width, rect.height);

BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

inline void serialize(std::ostream &os, const ofMeshFace &mesh) {
    serialize(os, mesh.hasColors());
    serialize(os, mesh.hasNormals());
    serialize(os, mesh.hasTexcoords());
    for(int i = 0; i < 3; i++) {
        serialize(os, mesh.getVertex(i));
        if(mesh.hasNormals()) serialize(os, mesh.getNormal(i));
        if(mesh.hasColors()) serialize(os, mesh.getColor(i));
        if(mesh.hasTexcoords()) serialize(os, mesh.getTexCoord(i));
    }
}

inline void deserialize(std::istream &is, ofMeshFace &mesh) {
    bool hasColors, hasNormals, hasTexcoords;
    deserialize(is, hasColors);
    mesh.setHasColors(hasColors);
    deserialize(is, hasNormals);
    mesh.setHasNormals(hasNormals);
    deserialize(is, hasTexcoords);
    mesh.setHasTexcoords(hasTexcoords);
    
    ofVec3f vertex, normal;
    ofFloatColor color;
    ofVec2f texcoord;
    
    for(int i = 0; i < 3; i++) {
        deserialize(is, vertex);
        if(hasNormals) {
            deserialize(is, normal);
            mesh.setNormal(i, normal);
        }
        if(hasColors) {
            deserialize(is, color);
            mesh.setColor(i, color);
        }
        if(hasTexcoords) {
            deserialize(is, texcoord);
            mesh.setTexCoord(i, texcoord);
        }
    }
}

enum ofMeshSerializeState {
    MeshDefault = 0,
    MeshHasVertices   = 1 << 0,
    MeshHasColors     = 1 << 1,
    MeshHasNormals    = 1 << 2,
    MeshHasTexCoords  = 1 << 3,
    MeshHasIndices    = 1 << 4,
    MeshUsingColors   = 1 << 5,
    MeshUsingTextures = 1 << 6,
    MeshUsingNormals  = 1 << 7,
    MeshUsingIndices  = 1 << 8
};

inline void serialize(std::ostream &os, const ofMesh &mesh) {
    uint16_t state;
    state = (mesh.hasVertices()   ? MeshHasVertices   : 0)
          | (mesh.hasColors()     ? MeshHasColors     : 0)
          | (mesh.hasNormals()    ? MeshHasNormals    : 0)
          | (mesh.hasTexCoords()  ? MeshHasTexCoords  : 0)
          | (mesh.hasIndices()    ? MeshHasIndices    : 0)
          | (mesh.usingColors()   ? MeshUsingColors   : 0)
          | (mesh.usingTextures() ? MeshUsingTextures : 0)
          | (mesh.usingNormals()  ? MeshUsingNormals  : 0)
          | (mesh.usingIndices()  ? MeshUsingIndices  : 0);
    serialize(os, state);
    
    if(mesh.hasVertices())  serialize(os, mesh.getVertices());
    if(mesh.hasColors())    serialize(os, mesh.getColors());
    if(mesh.hasNormals())   serialize(os, mesh.getNormals());
    if(mesh.hasTexCoords()) serialize(os, mesh.getTexCoords());
    if(mesh.hasIndices())   serialize(os, mesh.getIndices());
}

inline void deserialize(std::istream &is, ofMesh &mesh) {
    mesh.clear();
    uint16_t state;
    deserialize(is, state);
    
    if(state & MeshHasVertices)  deserialize(is, mesh.getVertices());
    if(state & MeshHasColors)    deserialize(is, mesh.getColors());
    if(state & MeshHasNormals)   deserialize(is, mesh.getNormals());
    if(state & MeshHasTexCoords) deserialize(is, mesh.getTexCoords());
    if(state & MeshHasIndices)   deserialize(is, mesh.getIndices());
    
    if(state & MeshUsingColors)   mesh.enableColors();
    else                          mesh.disableColors();
    
    if(state & MeshUsingTextures) mesh.enableTextures();
    else                          mesh.disableTextures();
    
    if(state & MeshUsingNormals)  mesh.enableNormals();
    else                          mesh.disableNormals();
    
    if(state & MeshUsingIndices)  mesh.enableIndices();
    else                          mesh.disableNormals();
}

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)

#undef BEGIN_NAMESPACE
#undef END_NAMESPACE
