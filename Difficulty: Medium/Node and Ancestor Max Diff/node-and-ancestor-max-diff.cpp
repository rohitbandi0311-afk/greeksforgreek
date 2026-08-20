class Solution {
private:
    int solve(Node* root, int& max_diff) {
        if (!root) return INT_MAX;

        // Leaf node has no descendants, so it cannot act as an ancestor
        if (!root->left && !root->right) {
            return root->data;
        }

        // Find the minimum value in left and right subtrees
        int left_min = solve(root->left, max_diff);
        int right_min = solve(root->right, max_diff);

        int min_child = min(left_min, right_min);

        // Maximize root->data - descendant
        max_diff = max(max_diff, root->data - min_child);

        // Return the minimum value in the subtree rooted at current node
        return min(root->data, min_child);
    }

public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        solve(root, max_diff);
        return max_diff;
    }
};