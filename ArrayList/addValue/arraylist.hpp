#include "list.hpp"
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

class ArrayList : public List {
    int* arr;
    int size;
    int capacity = 5;

    public:
    ArrayList(){
        arr = (int*)calloc(capacity, sizeof(int));
        size = 0;
    }

    //add
    void add(int num){
        if (size >= capacity){
            capacity = ceil(capacity * 1.5);
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
        arr[size++] = num;
    }

    //addAt
    void addAt(int pos, int num){
        if (pos < 5 && pos > 0){
            for (int i = size; i >= pos; i--){
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = num;
            size++;
        }
    }
    
    //remove
    int remove(int num){
        for (int i = 0; i < size; i++){
            if (arr[i] == num){
                for (int j = i; j < size - 1; j++){
                    arr[j] = arr[j + 1];
                }
                arr[size - 1] = 0;
                size -= 1;
                return i + 1;
            }
        }
        return -1;
    }

    //removeAt
    int removeAt(int pos){
        for (int i = 0; i < size; i++){
            if (i == pos - 1){
                for (int j = i; j < size - 1; j++){
                    arr[j] = arr[j + 1];
                }
                arr[size - 1] = 0;
                size -= 1;
                return pos;
            }
        }
        return -1;
    }

    //removeAll
    int removeAll(int num){
        int ctr = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] == num){
                for (int j = i; j < size -1; j++){
                    arr[j] = arr[j + 1];
                }
                arr[size - 1] = 0;
                size -= 1;
                ctr++;
                i--;
            }
        }
        return ctr;
    }

    //flip
    void flip(){
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //plus
    void plus(int term){
        for (int i = 0; i < size; i++){
            arr[i] += term;
        }
    }

    //summation
    int summation(){
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += arr[i];
        }

        return sum;
    }

    //get
    int get(int pos){
        return arr[pos - 1];
    }

    //print
    void print(){
        for (int i = 0; i < 5; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};