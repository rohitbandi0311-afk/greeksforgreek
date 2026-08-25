class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        // dp[x] stores the length of consecutive increasing subsequence ending at x
        unordered_map<int, int> dp;
        int max_len = 0;

        for (int num : arr) {
            dp[num] = dp[num - 1] + 1;
            max_len = max(max_len, dp[num]);
        }

        return n - max_len;
    }
};