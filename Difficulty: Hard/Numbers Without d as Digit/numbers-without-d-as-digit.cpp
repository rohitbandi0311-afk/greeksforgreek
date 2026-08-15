#include <string>
#include <cstring>

using namespace std;

class Solution {
    int dp[15][2][2];
    string s;
    int target_d;

    int solve(int idx, bool tight, bool lead_zero) {
        // Base case: If we have formed a complete number
        if (idx == s.length()) {
            // Return 0 if it's all leading zeros (i.e., the number 0), else return 1
            return lead_zero ? 0 : 1;
        }

        // Return precalculated results if available
        if (dp[idx][tight][lead_zero] != -1) {
            return dp[idx][tight][lead_zero];
        }

        // Determine the maximum digit we can place at the current position
        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for (int dig = 0; dig <= limit; ++dig) {
            // Skip the digit if it matches 'd'. 
            // Exception: If d == 0 and it's a leading zero, it's allowed because leading zeros aren't part of the final number.
            if (dig == target_d && !(target_d == 0 && lead_zero)) {
                continue;
            }

            // Recurse for the next digit
            ans += solve(idx + 1, 
                         tight && (dig == limit), 
                         lead_zero && (dig == 0));
        }

        return dp[idx][tight][lead_zero] = ans;
    }

public:
    int countWithout(int n, int d) {
        s = to_string(n);
        target_d = d;

        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Start processing from the 0th index, with strict upper bound (tight = true), and leading zeros allowed (lead_zero = true)
        return solve(0, true, true);
    }
};