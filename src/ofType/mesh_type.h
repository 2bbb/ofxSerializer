BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

namespace {
    enum ofMeshFaceSerializeState {
        MeshFaceDefault      = 0,
        MeshFaceHasColors    = 1 << 0,
        MeshFaceHasNormals   = 1 << 1,
        MeshFaceHasTexCoords = 1 << 2
    };
};

#define dirty_cast(type, value) reinterpret_cast<type(&)[3]>(const_cast<type &>(value))

inline void serialize(std::ostream &os, const ofMeshFace &mesh) {
    uint8_t state = (mesh.hasColors()    ? MeshFaceHasColors    : 0)
                  | (mesh.hasNormals()   ? MeshFaceHasNormals   : 0)
                  | (mesh.hasTexcoords() ? MeshFaceHasTexCoords : 0);
    serialize(os, state);
    
#if USE_DIRTY_OFFENSIVE_IMPLEMENTATION
    serialize(os, dirty_cast(ofVec3f, mesh.getVertex(0)));
    if(mesh.hasNormals())
        serialize(os, dirty_cast(ofVec3f, mesh.getNormal(0)));
    if(mesh.hasNormals())
        serialize(os, dirty_cast(ofFloatColor, mesh.getColor(0)));
    if(mesh.hasNormals())
        serialize(os, dirty_cast(ofVec2f, mesh.getTexCoord(0)));
#else
    for(int i = 0; i < 3; i++) {
        serialize(os, mesh.getVertex(i));
        if(mesh.hasNormals())   serialize(os, mesh.getNormal(i));
        if(mesh.hasColors())    serialize(os, mesh.getColor(i));
        if(mesh.hasTexcoords()) serialize(os, mesh.getTexCoord(i));
    }
#endif /* USE_DIRTY_OFFENSIVE_IMPLEMENTATION */
}

inline void deserialize(std::istream &is, ofMeshFace &mesh) {
    uint8_t state;
    deserialize(is, state);
    
    ofVec3f vertex, normal;
    ofFloatColor color;
    ofVec2f texcoord;
    
    mesh.setHasNormals((state & MeshFaceHasNormals) != 0);
    mesh.setHasColors((state & MeshFaceHasColors) != 0);
    mesh.setHasTexcoords((state & MeshFaceHasTexCoords) != 0);
    
#if USE_DIRTY_OFFENSIVE_IMPLEMENTATION
    deserialize(is, dirty_cast(ofVec3f, mesh.getVertex(0)));
    if(mesh.hasNormals())
        deserialize(is, dirty_cast(ofVec3f, mesh.getNormal(0)));
    if(mesh.hasNormals())
        deserialize(is, dirty_cast(ofFloatColor, mesh.getColor(0)));
    if(mesh.hasNormals())
        deserialize(is, dirty_cast(ofVec2f, mesh.getTexCoord(0)));
#else
    for(int i = 0; i < 3; i++) {
        deserialize(is, vertex);
        if(mesh.hasNormals()) {
            deserialize(is, normal);
            mesh.setNormal(i, normal);
        }
        if(mesh.hasColors()) {
            deserialize(is, color);
            mesh.setColor(i, color);
        }
        if(mesh.hasTexcoords()) {
            deserialize(is, texcoord);
            mesh.setTexCoord(i, texcoord);
        }
    }
#endif /* USE_DIRTY_OFFENSIVE_IMPLEMENTATION */
}
#undef dirty_cast

namespace {
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
