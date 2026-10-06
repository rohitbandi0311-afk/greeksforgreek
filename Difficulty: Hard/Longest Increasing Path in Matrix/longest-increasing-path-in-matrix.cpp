#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dfs(int r, int c, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // If already computed, return the memoized value
        if (dp[r][c] != 0) {
            return dp[r][c];
        }

        int maxLen = 1;
        // Direction vectors for moving up, down, left, and right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundaries and strict increasing condition
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] > matrix[r][c]) {
                maxLen = max(maxLen, 1 + dfs(nr, nc, n, m, matrix, dp));
            }
        }

        return dp[r][c] = maxLen;
    }

public:
    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        if (n == 0 || m == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int globalMax = 1;

        // Start DFS from every cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                globalMax = max(globalMax, dfs(i, j, n, m, matrix, dp));
            }
        }

        return globalMax;
    }
};