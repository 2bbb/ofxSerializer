BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)

class AbstractArchiveTarget {
public:
    virtual void archive(ostream &os) const {}
    virtual void extract(istream &is) {}
};

template <typename T>
class ArchiveTarget : public AbstractArchiveTarget {
public:
    ArchiveTarget(T &t)
    : t(t) {};
    virtual void archive(ostream &os) const {
        serialize(os, t);
    }
    virtual void extract(istream &is) {
        deserialize(is, t);
    }
private:
    T &t;
};

class Archiver {
    typedef map<string, shared_ptr<AbstractArchiveTarget> > Map;
public:
    Archiver(const string &extension = "bin",
             const string &prefix = "archiver",
             const string &pathOfDirectory = "")
    {
        snapshotCount = 0;
        lastArchive = "";
        setup(extension, prefix, pathOfDirectory);
    }
    
    void setup(const string &extension = "bin",
               const string &prefix = "archiver",
               const string &pathOfDirectory = "")
    {
        this->extension = extension;
        this->prefix = prefix;
        this->pathOfDirectory = pathOfDirectory;
    }
    
    void snapshot() {
        string filePath = ofVAArgsToString("%s%s_%ul_%ld.%s", pathOfDirectory.c_str(), prefix.c_str(), snapshotCount++, ofGetFrameNum(), extension.c_str());
        save(filePath);
    }
    
    void save(const string &filePath) {
        lastArchive = filePath;
        ofstream ofs;
        ofs.open(ofToDataPath(filePath, true).c_str(), std::ios::out | std::ios::binary);
        for(Map::const_iterator it = targets.begin(); it != targets.end(); it++) {
            const string &str = it->first;
            serialize(ofs, str);
            it->second->archive(ofs);
        }
        ofs.close();
    }
    
    void reloadLastArchive() {
        if(lastArchive != "") load(lastArchive);
    }
    
    void load(const string &filePath) {
        ifstream ifs;
        ifs.open(ofToDataPath(filePath, true).c_str(), std::ios::in | std::ios::binary);
        string key;
        while(ifs) {
            deserialize(ifs, key);
            if(targets.find(key) != targets.end()) targets[key]->extract(ifs);
        }
        ifs.close();
    }
    
    template <typename T>
    void insert(const string &key, T &object) {
        targets.insert(make_pair(key, shared_ptr<AbstractArchiveTarget>(static_cast<AbstractArchiveTarget *>(new ArchiveTarget<T>(object)))));
    }
    
    const string &getLastArchiveName() const {
        return lastArchive;
    }
private:
    string extension, prefix, pathOfDirectory;
    string lastArchive;
    Map targets;
    mutable size_t snapshotCount;
};

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)