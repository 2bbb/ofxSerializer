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

class ofApp : public ofBaseApp {
public:
    void setup() {
        SerializeDefinedStructTest();
        OtherStructTest();
        JsonizeTest();
        ofExit();
    }
    
private:
    float x, y;
    
    DefineSerializeMethod(x, y);
};

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}
