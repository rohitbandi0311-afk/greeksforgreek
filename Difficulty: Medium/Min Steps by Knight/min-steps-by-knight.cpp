#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Convert 1-based indexing to 0-based indexing
        int startX = knightPos[0] - 1;
        int startY = knightPos[1] - 1;
        int targetX = targetPos[0] - 1;
        int targetY = targetPos[1] - 1;
        
        // If the starting position is already the target position
        if (startX == targetX && startY == targetY) return 0;
        
        // Visited grid to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Queue stores {x, y, steps}
        queue<vector<int>> q;
        q.push({startX, startY, 0});
        visited[startX][startY] = true;
        
        // All 8 possible moves for a Knight
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int x = curr[0];
            int y = curr[1];
            int steps = curr[2];
            
            // Check all 8 directions
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // If the new position is valid and has not been visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (nx == targetX && ny == targetY) {
                        return steps + 1;
                    }
                    visited[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }
        
        return -1; // If target is unreachable (though always reachable on a standard chessboard)
    }
};