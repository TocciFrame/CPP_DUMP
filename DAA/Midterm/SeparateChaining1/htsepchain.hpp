#include <iostream>

using namespace std;

class htsepchain {

    int** table;
    int* count;
    int N;
    static const int bucket_size = 5;

    public:
    htsepchain(int n) {
        this->N = n;
        this->table = new int*[N];
        count = new int[N];

        for (int i = 0; i < N; i++) {

            table[i] = new int[bucket_size];
            for (int j = 0; j < bucket_size; j++) {
                table[i][j] = -1;
            }
        }
    }
    int hashfn(int key) {
        return compression(hash_code(key));
    }

    int hash_code(int key) {
        return key;
    }

    int compression(int code) {
        int a = 59, b = 17, p = 509;
        return (((a*code) + b) % p) % N;
    }

    int insert(int key) {   
        int hash = this->hashfn(key);

        for (int i = 0; i < bucket_size; i++) {
            if (table[hash][i] == -1) {
                table[hash][i] = key;
                count[hash]++;
                return count[hash];
            }

            if (table[hash][i] == key) {
                throw logic_error("Key already added: " + to_string(key));
            }
        }

        throw logic_error("Array " + to_string(count[hash]) + " is full");
    }

    int search(int key) {
        int hash = this->hashfn(key);
        int traverse = 1; // or zero?
        
        for (int i = 0; i < bucket_size; i++) {
            if (table[hash][i] == key) {
                return traverse - 1; // or traverse lang;
            }
            traverse++;
        }
        return -1;
    }

    int remove(int key) {
        int hash = this->hashfn(key);

        for (int i = 0; i < bucket_size; i++) {
            if (table[hash][i] == key) {

                for (int j = i; j < bucket_size; j++) {
                    table[hash][j] = table[hash][j+1];
                }
                count[hash]--;

                for (int k = count[hash]; k < bucket_size; k++) {
                    table[hash][k] = -1;
                }

                return count[hash];
            }
        }
    }
};