#include <iostream>
using namespace std;

void towerOfHanoi(int n, char orig, char dest, char aux);

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

void towerOfHanoi(int n, char orig, char dest, char aux) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << orig << " to " << dest << endl;
        return;
    }

    towerOfHanoi(n - 1, orig, aux, dest);
    cout << "Move disk " << n << " from " << orig << " to " << dest << endl;
    towerOfHanoi(n - 1, aux, dest, orig);
}