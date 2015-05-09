#include "ofMain.h"
#include "ofxSerializer.h"

struct Serializable {
    int id;
    string name;
    vector<ofPoint> points;
    float lifeTime;
    Serializable *next;
    int nums[3];
    
    Serializable() : next(NULL)  {};
    
    DefineSerializeMethod(id, name, points, lifeTime, next, nums);
};

struct DerivedSerializable : Serializable {
    ofRectangle space;
    
    DefineSerializeMethod(Super(Serializable, DerivedSerializable), space);
};

void SerializeDefinedStructTest() {
    Serializable encode1, *encode2 = new Serializable;
    
    encode1.id = 1;
    encode1.name = "decode1";
    for(int i = 0; i < 10; i++) encode1.points.push_back(ofPoint(i, 2 * i));
    encode1.lifeTime = 10.0f;
    encode1.next = encode2;
    encode1.nums[0] = 1;
    encode1.nums[1] = 2;
    encode1.nums[2] = 3;
    
    encode2->id = 2;
    encode2->name = "decode2";
    encode2->next = NULL;
    
    stringstream s("");
    encode1.serialize(s);
    encode1.saveToFile("encode1.serialized");
    Serializable decode;
    decode.deserialize(s);
    
    stringstream logstream("");
    for(int i = 0; i < decode.points.size(); i++) logstream << "(" << decode.points[i] << ") ,";
    ofLogNotice("SerializeDefinedStructTest")
        << decode.id << ", "
        << decode.name << ", "
        << decode.lifeTime << ", "
        << decode.nums[0] << ", "
        << decode.nums[1] << ", "
        << decode.nums[2] << ", "
        << logstream.str();
    
#define TEST_ASSERT(name) assert(encode1.name == decode.name);
    TEST_ASSERT(id);
    TEST_ASSERT(name);
    for(int i = 0; i < 10; i++) TEST_ASSERT(points[i]);
    TEST_ASSERT(lifeTime);
    for(int i = 0; i < 3; i++) TEST_ASSERT(nums[i]);
#undef TEST_ASSERT
    
    ofLogNotice("SerializeDefinedStructTest")
        << decode.next->id << ", "
        << decode.next->name << ", "
        << decode.next->lifeTime;
    
#define TEST_ASSERT(name) assert(encode2->name == decode.next->name);
    TEST_ASSERT(id);
    TEST_ASSERT(name);
#undef TEST_ASSERT
    
    DerivedSerializable derivedDecode;
    derivedDecode.loadFromFile("encode1.serialized");
    
    logstream.clear();
    for(int i = 0; i < derivedDecode.points.size(); i++) logstream << "(" << derivedDecode.points[i] << ") ,";
    ofLogNotice("SerializeDefinedStructTest")
        << derivedDecode.id << ", "
        << derivedDecode.name << ", "
        << derivedDecode.lifeTime << ", "
        << derivedDecode.nums[0] << ", "
        << derivedDecode.nums[1] << ", "
        << derivedDecode.nums[2] << ", "
        << logstream.str();
    
#define TEST_ASSERT(name) assert(encode1.name == derivedDecode.name);
    TEST_ASSERT(id);
    TEST_ASSERT(name);
    for(int i = 0; i < 10; i++) TEST_ASSERT(points[i]);
    TEST_ASSERT(lifeTime);
    for(int i = 0; i < 3; i++) TEST_ASSERT(nums[i]);
#undef TEST_ASSERT
    
    ofLogNotice("SerializeDefinedStructTest")
        << derivedDecode.next->id << ", "
        << derivedDecode.next->name << ", "
        << derivedDecode.next->lifeTime;
    
#define TEST_ASSERT(name) assert(encode2->name == derivedDecode.next->name);
    TEST_ASSERT(id);
    TEST_ASSERT(name);
#undef TEST_ASSERT
    cout << endl;
}

struct Z {
    int x, y;
};

DefineSerializeFunction(Z, v, v.x, v.y);

struct W {
    Z z;
};

DefineSerializeFunction(W, w, w.z);

void OtherStructTest() {
    stringstream s("");
    
    W w1, w2;
    w1.z.x = 2, w1.z.y = 4;
    
    ofxSerializer::serialize(s, w1);
    ofxSerializer::deserialize(s, w2);
    
    ofLogNotice("OtherStructTest") << w1.z.x << ", " << w1.z.y;
    ofLogNotice("OtherStructTest") << w2.z.x << ", " << w2.z.y;
    
#define TEST_ASSERT(name) assert(w1.name == w2.name);
    TEST_ASSERT(z.x);
    TEST_ASSERT(z.y);
#undef TEST_ASSERT
    cout << endl;
}

struct Jsonizable {
    float p, q;
    vector<string> ss;
    
    DefineJsonizeMethod(p, q, ss);
};

void JsonizeTest() {
    Jsonizable jsonizable;
    jsonizable.p = 10.0f;
    jsonizable.q = 20.0f;
    for(int i = 0; i < 30; i += 3) jsonizable.ss.push_back(ofVAArgsToString("jsn_%03d", i));
    stringstream s("");
    jsonizable.jsonize(s);
    ofLogNotice("JsonizeTest") << s.str();
}

inline void clearStringStream(stringstream &ss) {
    ss.str("");
    ss.clear(stringstream::goodbit);
}

template <typename From, typename To>
inline void testSerialize(stringstream &ss, const From &from, To &to) {
    ofxSerializer::serialize(ss, from);
    ofxSerializer::deserialize(ss, to);
    clearStringStream(ss);
}

void ofMathTypesTest() {
    stringstream s;
    
    {
        ofVec2f v2s(2.1f, 2.2f), v2d;
        ofVec3f v3s(3.1f, 3.2f, 3.3f), v3d;
        ofVec4f v4s(4.1f, 4.2f, 4.3f, 4.4f), v4d;
        
        {
            testSerialize(s, v2s, v2d);
            assert(v2s.x == v2d.x && v2s.y == v2d.y);
            
            testSerialize(s, v2s, v3d);
            assert(v2s.x == v3d.x && v2s.y == v3d.y);

            testSerialize(s, v2s, v4d);
            assert(v2s.x == v4d.x && v2s.y == v4d.y);
        }
        
        {
            testSerialize(s, v3s, v2d);
            assert(v3s.x == v2d.x && v3s.y == v2d.y);
            
            testSerialize(s, v3s, v3d);
            assert(v3s.x == v3d.x && v3s.y == v3d.y && v3s.z == v3d.z);
            
            testSerialize(s, v3s, v4d);
            assert(v3s.x == v4d.x && v3s.y == v4d.y && v3s.z == v4d.z);
        }
        
        {
            testSerialize(s, v4s, v2d);
            assert(v4s.x == v2d.x && v4s.y == v2d.y);
            
            testSerialize(s, v4s, v3d);
            assert(v4s.x == v3d.x && v4s.y == v3d.y && v4s.z == v3d.z);

            testSerialize(s, v4s, v4d);
            assert(v4s.x == v4d.x && v4s.y == v4d.y && v4s.z == v4d.z && v4s.w == v4d.w);
        }
    }
    
    {
        ofMatrix3x3 mat3x3s(1.1f, 1.2f, 1.3f,
                            2.1f, 2.1f, 2.3f,
                            3.1f, 3.1f, 3.3f),
                    mat3x3d;
        testSerialize(s, mat3x3s, mat3x3d);
        for(int i = 0; i < 9; i++) assert(mat3x3s[i] == mat3x3d[i]);
        
        ofMatrix4x4 mat4x4s(1.1f, 1.2f, 1.3f, 1.4f,
                            2.1f, 2.2f, 2.3f, 2.4f,
                            3.1f, 3.2f, 3.3f, 3.4f,
                            4.1f, 4.2f, 4.3f, 4.4f),
                    mat4x4d;
        testSerialize(s, mat4x4s, mat4x4d);
        for(int i = 0; i < 16; i++) assert(mat4x4s(i / 4, i % 4) == mat4x4d(i / 4, i % 4));
        
        ofQuaternion qs(1.1f, 2.2f, 3.3f, 4.4f), qd;
        testSerialize(s, qs, qd);
        assert(   qs.x() == qd.x()
               && qs.y() == qd.y()
               && qs.z() == qd.z()
               && qs.w() == qd.w());
    }
}

static const int particleSize = 100;

class ofApp : public ofBaseApp {
public:
    void setup() {
        SerializeDefinedStructTest();
        OtherStructTest();
        ofMathTypesTest();
        JsonizeTest();
        
//        ofExit();
        
        ofEnableAlphaBlending();
        ofEnableSmoothing();
        
        for(int i = 0; i < particleSize; i++) {
            points[i].set(ofRandomWidth(), ofRandomHeight());
            accels[i].set(ofRandomf(), ofRandomf());
        }
        
        archiver.setup();
        seed = ofRandom(0, 65535);
        archiver.insert("points", points);
        archiver.insert("accels", accels);
        archiver.insert("seed", seed);
        
        ofSeedRandom(seed);
    }
    
    void update() {
        for(int i = 0; i < particleSize; i++) {
            points[i] += accels[i];
            accels[i] += ofRandomf() * 0.1f;
        }
    }
    
    void draw() {
        ofBackground(0);
        ofSetColor(255);
        
        ofDrawBitmapString("Press Space : take snapshot", ofPoint(10, 20));
        ofDrawBitmapString("Press Enter : load last snapshot", ofPoint(10, 40));
        
        ofSetColor(255, 128);
        
        for(int i = 0; i < particleSize; i++) {
            ofCircle(points[i], 3.0f);
        }
    }
    
    void keyPressed(int key) {
        if(key == ' ') {
            archiver.snapshot();
        } else if(key == OF_KEY_RETURN) {
            archiver.reloadLastArchive();
            ofSeedRandom(seed);
        }
    }
    
private:
    ofPoint points[particleSize];
    ofVec2f accels[particleSize];
    int seed;
    DefineSerializeMethod(points, accels, seed);
    ofxSerializer::Archiver archiver;
};

//========================================================================
int main( ){
    ofSetupOpenGL(1024, 768, OF_WINDOW);
    ofRunApp(new ofApp);
}
