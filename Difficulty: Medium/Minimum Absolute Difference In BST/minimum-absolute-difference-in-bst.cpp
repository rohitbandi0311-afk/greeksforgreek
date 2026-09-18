class Solution {
private:
    void inorder(Node* root, int& prev, int& minDiff) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left, prev, minDiff);

        // Process current node
        if (prev != -1) {
            minDiff = min(minDiff, root->data - prev);
        }
        prev = root->data;

        // Traverse right subtree
        inorder(root->right, prev, minDiff);
    }

public:
    int absDiff(Node* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};