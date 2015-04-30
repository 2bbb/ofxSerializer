#include "ofMain.h"
#include "ofxSerializer.h"

struct X {
    float x, y;
    int z;
    
    std::vector<int> ws;
    std::string s, t;
    std::vector<std::string> ss;
    
    X() {};
    X(float x, float y, int z, const std::string &s, const std::string &t)
    : x(x), y(y), z(z), s(s), t(t) {};
    
    DefineSerializeMethod(x, y, z, s, t, ws, ss);
};

struct Y : X {
    Y(float x, float y, int z, const std::string &s, const std::string &t, float p, float q)
    : X(x, y, z, s, t), p(p), q(q) {};
    float p, q;
    DefineSerializeMethod(Super(X, Y), p, q);
};

struct Z {
    int x, y;
};

DefineSerializeFunction(Z, v, v.x, v.y);

void SerializeDefinedStructTest() {
    stringstream s("");
    X x(1.0f, 2.0f, 3, "abcdefgh", "0123456");
    Y y(0.0f, 0.0f, 0, "", "", 1.0f, 2.0f);
    
    for(int i = 0; i < 100; i++) x.ws.push_back(i);
    x.ss.push_back("123");
    x.ss.push_back("456");
    x.ss.push_back("789abcdef");
    x.serialize(s);
    
    y.deserialize(s);
    ofLogNotice("SerializeDefinedStructTest") << y.x << ", " << y.y << ", " << y.z << ", " << y.s << ", " << y.t;
    for(size_t i = 0; i < y.ws.size(); i++) cout << y.ws[i] << ", ";
    for(size_t i = 0; i < y.ss.size(); i++) cout << y.ss[i] << ", ";
    ofLogNotice("SerializeDefinedStructTest") << y.p << ", " << y.q;
}

struct W {
    Z z;
};

void OtherStructTest() {
    stringstream s("");
    
    W w1, w2;
    w1.z.x = 2, w1.z.y = 4;
    
    ofxSerializer::serialize(s, w1);
    ofxSerializer::deserialize(s, w2);
    ofLogNotice("OtherStructTest") << w1.z.x << ", " << w1.z.y;
    ofLogNotice("OtherStructTest") << w2.z.x << ", " << w2.z.y;
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
    for(int i = 0; i < 200; i += 3) jsonizable.ss.push_back(ofVAArgsToString("jsn_%03d", i));
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
