#include <iostream>
#include <cstdlib>
#include <cmath>
#include "minheap.hpp"
using namespace std;

class ArrayMinHeap : public MinHeap {
    int* array;
    int size;
    int capacity = 5;

	int left(int n) {
        return 2 * n + 1;
	}

	int right(int n) {
        return left(n) + 1;
	}

    public:
    ArrayMinHeap() {
    	size = 0;
    	array = (int*)calloc(0, sizeof(int));
	}

	void insert(int num) {
	    if (size >= capacity){
            capacity = ceil(capacity * 1.5);
            array = (int*)realloc(array, capacity * sizeof(int));
        }
	    
        array[size] = num;
        int index = size;
        size++;
        
        while(index > 0){
            int par = (index - 1) / 2;
            if (array[index] < array[par]){
                swap(array[index], array[par]);
                index = par;
            }else {
                break;
            }
        }
	}
	
	void heap(int index){
	    while (true){
	        int l = left(index);
	        int r = right(index);
	        int smallest = index;
	    
	        if (l < size && array[l] < array[smallest]){
	            smallest = l;
	        }
	    
	        if (r < size && array[r] < array[smallest]){
	            smallest = r;
	        }
	    
	        if (smallest != index){
	            swap(array[index], array[smallest]);
	            index = smallest;
	        } else {
	            break;
	        }
	    }
	}

	int removeMin() {
		if (size == 0){
		    return -1;
		}
		
		if (size == 1){
		    size--;
		    return array[0];
		}
		
		int root = array[0];
		array[0] = array[size - 1];
		size--;
		heap(0);
		
		if (size < ceil(capacity * (3.0) / 4)){
	        capacity = ceil(capacity * 0.8);
	        if (capacity < 5){
	            capacity = 5;
	        }
	        array = (int*)realloc(array, capacity * sizeof(int));
	    }
		
		return root;
	}

    // DO NOT modify the code below
	void print() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
			cout << "Size: " << size << "/" << capacity << endl;
			cout << "TREE: " << endl;
			print_tree("", 0, false);

		cout << "ARRAY: ";
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void print_tree(string prefix, int n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
		if (left(n) < size) {
			print_tree(prefix + "|   ", left(n), true);
		}
		if (right(n) < size) {
			print_tree(prefix + "|   ", right(n), false);
		}
	}
};