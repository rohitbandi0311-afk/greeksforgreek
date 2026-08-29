class Solution {
public:
    int countSubsequences(string &s, int n) {
        int MOD = 1e9 + 7;
        int len = s.length();
        
        // dp[r] holds the number of subsequences with remainder 'r' modulo n
        vector<long long> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            vector<long long> next_dp = dp;

            // Start a new subsequence with just this digit
            next_dp[digit % n] = (next_dp[digit % n] + 1) % MOD;

            // Extend existing subsequences
            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * 10 + digit) % n;
                    next_dp[new_rem] = (next_dp[new_rem] + dp[r]) % MOD;
                }
            }

            dp = move(next_dp);
        }

        // dp[0] contains the count of all non-empty subsequences divisible by n
        return dp[0];
    }
};