class Solution {
public:
    void getLeafCosts(Node* root, int level, vector<int>& leafCosts) {
        if (!root) return;

        // If it's a leaf node, store its level as its cost
        if (!root->left && !root->right) {
            leafCosts.push_back(level);
            return;
        }

        getLeafCosts(root->left, level + 1, leafCosts);
        getLeafCosts(root->right, level + 1, leafCosts);
    }

    int getCount(Node* root, int k) {
        vector<int> leafCosts;
        // Root is at level 1
        getLeafCosts(root, 1, leafCosts);

        // Sort costs in ascending order to pick the cheapest leaves first
        sort(leafCosts.begin(), leafCosts.end());

        int count = 0;
        int currentCost = 0;

        for (int cost : leafCosts) {
            if (currentCost + cost <= k) {
                currentCost += cost;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};