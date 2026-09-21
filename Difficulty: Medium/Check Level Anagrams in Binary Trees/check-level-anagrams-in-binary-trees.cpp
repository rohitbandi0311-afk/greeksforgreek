class Solution {
public:
    bool areAnagrams(Node *root1, Node *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int size1 = q1.size();
            int size2 = q2.size();

            // If the number of nodes at the current level differs, they can't be anagrams
            if (size1 != size2) return false;

            unordered_map<int, int> freqMap;

            // Process nodes of the first tree for the current level
            for (int i = 0; i < size1; i++) {
                Node* node1 = q1.front();
                q1.pop();
                freqMap[node1->data]++;

                if (node1->left) q1.push(node1->left);
                if (node1->right) q1.push(node1->right);
            }

            // Process nodes of the second tree for the current level
            for (int i = 0; i < size2; i++) {
                Node* node2 = q2.front();
                q2.pop();

                // If the element doesn't exist or frequency is already 0, mismatch found
                if (freqMap.find(node2->data) == freqMap.end() || freqMap[node2->data] == 0) {
                    return false;
                }

                freqMap[node2->data]--;

                if (node2->left) q2.push(node2->left);
                if (node2->right) q2.push(node2->right);
            }

            // Check if any frequency counts remain unmatched
            for (auto& pair : freqMap) {
                if (pair.second != 0) return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};