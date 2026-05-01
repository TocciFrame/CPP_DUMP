#include "node.hpp"
#include <iostream>
#include <climits>
using namespace std;
class Heap {
    node** arr;
    int s;
    
    int left(int n) {
        return 2 * n + 1;
    }
    
    int right(int n) {
        return left(n) + 1;
    }
    
    int parent(int index) {
        return (index - 1) / 2;
    }
    
    void swap(int i, int j) {
        node* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    void bubbleUp(int i) {
        while(i > 0) {
            int par = parent(i);
            
            if (arr[i]->weight < arr[par]->weight) {
                swap(i, par);
                i = par;
            } else {
                break;
            }
        }
    }
    
    void bubbleDown(int i) {
        while(true) {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            
            if (l < s && arr[l]->weight < arr[smallest]->weight) {
                smallest = l;
            }
            
            if (r < s) {
                if (arr[r]->weight < arr[smallest]->weight) {
                    smallest = r;
                }
            }
            
            if (smallest != i) {
                swap(i, smallest);
                i = smallest;
            } else {
                break;
            }
        }
    }
    
	public:
	Heap() {
	    s = 0;
	    arr = new node*[1000];
	}
	
    // TODO insert
	void insert(node* n) {
	    arr[s] = n;
	    bubbleUp(s);
	    s++;
	}

    // TODO removeMin
	node* removeMin() {
	    if (s == 0) return nullptr;
	    
	    node* root = arr[0];
	    arr[0] = arr[s - 1];
	    s--;
	    
	    if (s > 0) {
	        bubbleDown(0);
	    }
	    return root;
	}

    // TODO size
	int size() {
		return s;;
	}
};