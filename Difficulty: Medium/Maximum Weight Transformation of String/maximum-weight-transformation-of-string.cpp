class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.length();
        if (n == 0) return 0;

        // dp[i] represents max weight from index i to n-1
        // We only need the last two values to save space (O(1) space)
        int next1 = 0; // represents dp[i+1]
        int next2 = 0; // represents dp[i+2]

        // Base case: single character at the end
        next1 = 1; // s[n-1] unpaired contributes 1

        for (int i = n - 2; i >= 0; --i) {
            // Option 1: Leave s[i] unpaired
            int current = 1 + next1;

            // Option 2: Pair s[i] and s[i+1]
            int pairContribution = (s[i] != s[i+1]) ? 4 : 3;
            current = max(current, pairContribution + next2);

            // Shift DP pointers
            next2 = next1;
            next1 = current;
        }

        return next1;
    }
};