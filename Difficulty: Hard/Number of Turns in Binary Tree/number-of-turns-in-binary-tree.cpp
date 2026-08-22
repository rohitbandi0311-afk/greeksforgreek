class Solution {
private:
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) 
            return root;

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    bool countTurns(Node* root, int target, bool turn, int& count) {
        if (!root) return false;
        if (root->data == target) return true;

        // Try left subtree (turn true means moving LEFT)
        if (countTurns(root->left, target, true, count)) {
            if (!turn) count++; // Direction changed from RIGHT to LEFT
            return true;
        }

        // Try right subtree (turn false means moving RIGHT)
        if (countTurns(root->right, target, false, count)) {
            if (turn) count++; // Direction changed from LEFT to RIGHT
            return true;
        }

        return false;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {
        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        int count = 0;

        if (lca->data == p) {
            countTurns(lca->left, q, true, count);
            countTurns(lca->right, q, false, count);
        } 
        else if (lca->data == q) {
            countTurns(lca->left, p, true, count);
            countTurns(lca->right, p, false, count);
        } 
        else {
            // Path goes through LCA: left child path + right child path + 1 turn at LCA
            countTurns(lca->left, p, true, count);
            countTurns(lca->right, p, false, count);
            countTurns(lca->left, q, true, count);
            countTurns(lca->right, q, false, count);
            count++; // Turn at LCA
        }

        return count == 0 ? -1 : count;
    }
};