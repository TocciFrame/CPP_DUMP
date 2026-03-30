#include <iostream>
#include "hashList.hpp"
using namespace std;

class SepChain : public HashList {
    int** table;
    int N;
    int* bucketSize;
    int count;

    public:
    SepChain(int N) {
        this->N = N;
        bucketSize = new int[N];
        this->table = new int*[N];
        this->count = 5;

        for (int i = 0; i < N; i++) {
            table[i] = new int[count];
            bucketSize[i] = 0;
        }
    }
    int hash_code(int key) {
            return key;
        }

    int compress(int code) {
        int a = 7, b = 3, p = 101;
        return (((code * a) + b) % p) % N;
    }

    void insert(int key) {
        int hash = this->hashfn(key);

        if (search(key) != -1) {
            throw logic_error("Already has key " + to_string(key));
        }
        if (bucketSize[hash] == count) {
            throw logic_error("Bucket " + to_string(hash) +  " has reached maximum capacity.");
        }
        table[hash][bucketSize[hash]] = key;
        bucketSize[hash]++;
    }

    int search(int key) {
        int hash = this->hashfn(key);

        for (int i = 0 ; i < N; i++) {
            if (table[hash][i] == key) {
                return i;
            }
        }
        return -1;
    }

    int remove(int key) {
        int hash = this->hashfn(key);
        int target = search(key);
        if (target == -1) {
            return -1;
        }
        for (int i = target; i < bucketSize[hash] - 1; i++) {
            table[hash][i] = table[hash][i + 1];
        }
        bucketSize[hash]--;
        return bucketSize[hash];
    }

    void print() {
        for (int i = 0; i < N; i++) {
            cout << i << "\t";
            for (int j = 0; j < bucketSize[i]; j++) {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }    
    }
};