class Solution {
public:
    int transform(string &s1, string &s2) {
        // Step 1: Base validation for lengths
        if (s1.length() != s2.length()) {
            return -1;
        }

        // Step 2: Check character frequencies (Anagram Check)
        unordered_map<char, int> count;
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (auto &pair : count) {
            if (pair.second != 0) {
                return -1;
            }
        }

        // Step 3: Greedy counting from the back
        int operations = 0;
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--; // Match found, advance s2 pointer
            } else {
                operations++; // Character needs to be moved to front
            }
            i--; // Always move s1 pointer backward
        }

        return operations;
    }
};