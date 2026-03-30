class List {
    public:
    virtual void addFirst(int num) = 0;
    virtual void addLast(int num) = 0;
    virtual void addAt(int num, int pos) = 0;
    virtual int removeFirst() = 0;
    virtual int removeLast() = 0;
    virtual int removeAt(int pos) = 0;
    virtual int get(int pos) = 0;
    virtual void print() = 0;
};