template <typename K>
class HashList {
    public:
    virtual int hash_code(K) = 0;
    virtual int compress(int) = 0;
    virtual int insert(K) = 0;
    virtual int remove(K) = 0;
    virtual int search(K) = 0;
    virtual void print() = 0;

    int hashfn(K key) {
        return (compress((int) key));
    }
};