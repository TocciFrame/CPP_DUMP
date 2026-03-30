#include <cstdlib>
#include <queue>
using namespace std;

struct node {
	node **children;
	node *parent;
	int num_child;
	int elem;

    int depth() {
		int d = 0;
		node* curr = parent;
		while(curr){
		    d++;
		    curr = curr->parent;
		}
        return d;
	}


    int height() {
		if (num_child == 0) return 0;
		
		int max = 0;
		for (int i = 0; i < num_child; i++){
		    int h = children[i]->height();
		    
		    if (h > max){
		        max = h;
		    }
		}
        return max + 1;
    }

    void bfs(node* root) {
        if (root == nullptr) return;

        queue<node*> q;
        q.push(root);

        while(!q.empty()) {
            node* curr = q.front();
            q.pop();

            cout << curr->elem << " ";

            if (curr->num_child > 0) {
                for (int i = 0; i < curr->num_child; i++) {
                    q.push(curr->children[i]);
                }
            }
        }
    }

    void dfs(node* root) {
        if (root == nullptr) return;

        cout << root->elem << " ";

        if (root->num_child > 0) {
            for (int i = 0; i < root->num_child; i++) {
                dfs(root->children[i]);
            }
        }
    }
};