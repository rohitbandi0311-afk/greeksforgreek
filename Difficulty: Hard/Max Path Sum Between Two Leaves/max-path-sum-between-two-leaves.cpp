class Solution {
private:
    int maxPathSumUtil(Node* root, int &res) {
        // Base case: if node is null, return 0
        if (!root) return 0;

        // If it's a leaf node, return its data
        if (!root->left && !root->right) return root->data;

        // Recursively find maximum path sum in left and right subtrees
        int leftSum = maxPathSumUtil(root->left, res);
        int rightSum = maxPathSumUtil(root->right, res);

        // If both left and right children exist, update the global maximum path sum between two leaves
        if (root->left && root->right) {
            res = max(res, leftSum + rightSum + root->data);

            // Return the maximum path sum extending from this node to one of its leaves
            return max(leftSum, rightSum) + root->data;
        }

        // If only one child exists, return the path through that child
        return (root->left) ? leftSum + root->data : rightSum + root->data;
    }

public:
    int maxPathSum(Node* root) {
        int res = -1e9; // Initialize with a very small number

        maxPathSumUtil(root, res);

        // If no such path exists (fewer than two leaves), return -1
        return (res == -1e9) ? -1 : res;
    }
};