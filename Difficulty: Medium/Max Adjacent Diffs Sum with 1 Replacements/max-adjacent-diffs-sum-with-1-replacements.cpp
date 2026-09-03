class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp0 tracks max sum ending with arr[i] replaced by 1
        // dp1 tracks max sum ending with arr[i] kept as original
        int dp0 = 0;
        int dp1 = 0;

        for (int i = 1; i < n; ++i) {
            int new_dp0 = max(dp0, dp1 + abs(arr[i - 1] - 1));
            int new_dp1 = max(dp0 + abs(arr[i] - 1), dp1 + abs(arr[i] - arr[i - 1]));

            dp0 = new_dp0;
            dp1 = new_dp1;
        }

        return max(dp0, dp1);
    }
};