struct Point {
    int x;
    int y;

    Point midpoint(Point* other){
        Point mid;
        mid.x = (this->x + other->x) / 2;
        mid.y = (this->y + other->y) / 2;
        return mid;
    }

    
};

typedef Point point;