DefineSerializeFunction(ofMatrix3x3, mat, mat.a, mat.b, mat.c, mat.d, mat.e, mat.f, mat.g, mat.h, mat.i);
DefineSerializeFunction(ofMatrix4x4, mat, mat._mat);
DefineSerializeFunction(ofQuaternion, quat, quat._v)
DefineSerializeFunction(ofVec2f, p, p.x, p.y);
DefineSerializeFunction(ofVec3f, p, p.x, p.y, p.z);
DefineSerializeFunction(ofVec4f, p, p.x, p.y, p.z, p.w);
