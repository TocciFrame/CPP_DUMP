class List {
    public:
    virtual void add(int num) = 0;
    virtual void addAt(int pos, int num) = 0;
    virtual int remove(int num) = 0;
    virtual int removeAt(int pos) = 0;
    virtual int removeAll(int num) = 0;
    virtual int get(int pos) = 0;
    virtual void flip() = 0;
    virtual void plus(int term) = 0;
    virtual int summation() = 0;
    virtual void print() = 0;
};