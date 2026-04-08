node* remove(node* curr, int num) {
        if (!curr) return nullptr;

        if (num < curr->elem) {
            curr->left = remove(curr->left, num);
        } else if (num > curr->elem) {
            curr->right = remove(curr->right, num);
        } else {
            if (!curr->left || !curr->right) {
                node* temp;
                if (curr->left) {
                    temp = curr->left;
                } else {
                     temp = curr->right;
                }

                if (!temp) {
                    delete root;
                    return nullptr;
                } else {
                    node* old = root;
                    root = temp;
                    delete old;
                }
            } else {
                node* temp = curr->right;
                while (temp->left) {
                    temp = temp->left;
                }
                curr->elem = temp->elem;
                curr->right = remove(curr->right, temp->elem);
            }
        }

        if (!root) return nullptr;

        curr->updateHeight(curr);
        int balanceFactor = curr->getBalanceFactor(curr);

        if (balanceFactor > 1) {
            if (curr->left->getBalanceFactor(curr->left) >= 0) {
                return curr->rotateRight(curr);
            } else {
                curr->left = curr->rotateLeft(curr->left);
                return curr->rotateRight(curr);
            }
        } else if (balanceFactor < -1) {
            if (curr->right->getBalanceFactor(curr->right) <= 0) {
                return curr->rotateLeft(curr);
            } else {
                curr->right = curr->rotateRight(curr->right);
                return curr->rotateLeft(curr);
            }
        }

        return curr;
    }