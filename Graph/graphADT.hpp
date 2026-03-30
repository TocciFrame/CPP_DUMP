class GraphADT {
    public:
    virtual int numVert() = 0;
    virtual int numEdge() = 0;
    virtual char* vertices() = 0;
    virtual int* edges() = 0;
    virtual void insertVertex(char) = 0;
};