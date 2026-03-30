class HashList {
    public:
    virtual int hash_code(int) = 0;
    virtual int compress(int) = 0;
    virtual void insert(int) = 0;
    virtual int search(int) = 0;    
    virtual int remove(int) = 0;
    virtual void print() = 0;

    int hashfn(int key) {
        return compress(hash_code(key));
    }
};