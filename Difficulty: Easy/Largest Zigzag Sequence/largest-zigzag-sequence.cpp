#include <vector>
#include <algorithm>

class Solution {
public:
    int zigzagSequence(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        
        // dp vector to store the max zigzag sum from the current row downwards
        std::vector<int> next_dp = mat[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            std::vector<int> curr_dp(n);
            
            // Find the maximum and second maximum values in next_dp along with their indices
            int max1 = -1, max2 = -1;
            int idx1 = -1;
            
            for (int j = 0; j < n; ++j) {
                if (next_dp[j] > max1) {
                    max2 = max1;
                    max1 = next_dp[j];
                    idx1 = j;
                } else if (next_dp[j] > max2) {
                    max2 = next_dp[j];
                }
            }
            
            for (int j = 0; j < n; ++j) {
                // If current column equals idx1, we must pick the second maximum
                int best_next = (j != idx1) ? max1 : max2;
                curr_dp[j] = mat[i][j] + best_next;
            }
            
            next_dp = curr_dp;
        }
        
        // The answer is the maximum value in the DP array for the first row
        return *std::max_element(next_dp.begin(), next_dp.end());
    }
};