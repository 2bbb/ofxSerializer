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

#include "jsonize_macros.h"

#define DefineJsonizeMethod(...) \
inline void jsonize(std::ostream &os) const { \
    os << "{"; \
    ofxSerializer::jsonize(os, MakeStringifiedPair(__VA_ARGS__)); \
    os << "}"; \
};