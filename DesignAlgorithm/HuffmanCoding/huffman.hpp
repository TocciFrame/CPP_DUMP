#include "heap.hpp"

// TODO huffman
node* huffman_code(Heap* heap) {
    if (heap->size() == 0) return nullptr;
    
    while(heap->size() > 1) {
        node* n1 = heap->removeMin();
        node* n2 = heap->removeMin();
        node* par = new node('\0', n1->weight + n2->weight);
        
        par->left = n1;
        par->right = n2;
        
        n1->parent = par;
        n2->parent = par;
        
        heap->insert(par);
    }
    
    return heap->removeMin();
}