#include <iostream>
#include "hashList.hpp"
using namespace std;

template <typename K>
class HashTable : public HashList<K> {
    K* table;
    int count;
    int N;

    public:
    HashTable<K>(int N) {
        table = new K[N];
        count = 0;
        this->N = N;

        for (int i = 0; i < N; i++) {
            table[i] = 0;
        }
    }

    int hash_code(K key) {
        return (int) key;
    }

    int compress(int code) {
        // return abs((((code * 59) + 17) % 509) % N);
        return code % N;
    }

    int insert(K key) {
        if (count >= N) {
            throw logic_error("Hash table is full");
        }
        if (search(key) != -1) {
            throw logic_error("Already exist key " + to_string(key));
        }

        int hash = this->hashfn(key);
        int probe = 0;

        while (table[hash] != 0 && table[hash] != -1 && table[hash] != key) {
            hash = (hash + 1) % N;
            probe++;
        }

        if (table[hash] == 0 || table[hash] == -1) {
            table[hash] = key;
            count++;
            return probe;
        }

        return -1;
    }

    int remove(K key) {
        int hash = this->hashfn(key);
        int probe = 0;
        int start = hash;

        while (table[hash] != 0) {
            if (table[hash] == key) {
                table[hash] = -1;
                count--;
                return probe;
            }
            hash = (hash + 1) % N;
            probe++;
            if (hash == start) break;
        }
        return -1;
    }

    int search(K key) {
        int hash = this->hashfn(key);
        int start = hash;
        int probe = 0;

        while (table[hash] != 0) {
            if (table[hash] == key) {
                return hash;
            }
            hash = (hash + 1) % N;
            probe++;
            if (hash == start) break;
        } 
        return -1;
    }


    void print() {
        for (int i = 0; i < N; i++) {
            cout << i << "\t";
        }
        cout << endl;

        for (int i = 0; i < N; i++) {
            if (table[i] == 0 || table[i] == -1) {
                cout << "0\t";
            } else {
                cout << table[i] << "\t";
            }
        }
        cout << endl;
    }
};