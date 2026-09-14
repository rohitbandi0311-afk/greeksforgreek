#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size(); // Fixed: use mat[0].size() for columns

        // safeMat keeps track of cells we are allowed to visit (1 = safe, 0 = unsafe)
        vector<vector<int>> safeMat(n, vector<int>(m, 1));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 1: Mark all unsafe cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    safeMat[i][j] = 0; // The landmine itself is unsafe
                    // Mark all 4-directional neighbors as unsafe
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            safeMat[ni][nj] = 0;
                        }
                    }
                }
            }
        }

        // Queue stores {row, col, distance}
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 2: Push all valid starting cells from the first column
        for (int i = 0; i < n; i++) {
            if (safeMat[i][0] == 1) {
                q.push({i, 0, 1}); // 1-indexed steps as per problem definition
                visited[i][0] = true;
            }
        }

        // Step 3: Perform BFS
        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            // If we reach any cell in the rightmost column, return the distance
            if (c == m - 1) {
                return dist;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && safeMat[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        // If no path to the last column exists
        return -1;
    }
};