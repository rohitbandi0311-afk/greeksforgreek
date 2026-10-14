class Solution {
public:
    string findRollOut(string &s, vector<int>& roll) {
        int n = s.size();
        vector<int> count(n + 1, 0);

        // Count frequencies of each roll operation length
        for (int r : roll) {
            count[r]++;
        }

        // Propagate the counts from right to left (prefix sum from back)
        int currentRolls = 0;
        for (int i = n; i >= 1; i--) {
            currentRolls += count[i];
            // Apply total shifts for the character at index (i - 1)
            int idx = i - 1;
            int shift = currentRolls % 26;
            s[idx] = 'a' + (s[idx] - 'a' + shift) % 26;
        }

        return s;
    }
};