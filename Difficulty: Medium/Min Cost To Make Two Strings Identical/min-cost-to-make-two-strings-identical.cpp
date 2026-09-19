#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size();
        int m = s2.size();

        // Find Length of Longest Common Subsequence (LCS)
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        int lcsLength = prev[m];

        // Calculate minimum deletion cost
        int deletionsFromS1 = n - lcsLength;
        int deletionsFromS2 = m - lcsLength;

        return (deletionsFromS1 * costS1) + (deletionsFromS2 * costS2);
    }
};