#include <iostream>
#include "point.hpp"
using namespace std;

int main(){
    Point p1, p2;

    cout << "P1: ";
    cin >> p1.x >> p1.y;
    cout << "P2: ";
    cin >> p2.x >> p2.y;

    cout << "P1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "P2: (" << p2.x << ", " << p2.y << ")" << endl;

    Point res = p1.midpoint(&p2);
    cout << "Midpoint: (" << res.x << ", " << res.y << ")" << endl;
}