class List{
    public:
    //ADDING VALUES
    virtual void add(int num) = 0;
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void addAt(int num, int pos) = 0;

    //REMOVING VALUES
    virtual int clear() = 0;
    virtual void remove(int num) = 0;
    virtual void removeAt(int pos) = 0;
    virtual int removeAll(int num) = 0;
    virtual void replace(int num, int pos) = 0;

    //OTHER OPERATIONS
    virtual void flip() = 0;
    virtual int get(int pos) = 0;
    virtual void print() = 0;
};