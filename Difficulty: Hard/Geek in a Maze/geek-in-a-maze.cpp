#include <vector>
#include <queue>

using namespace std;

class Solution {
    struct Node {
        int r, c, u, d;
        // Priority queue to min-heap based on total up + down moves used
        bool operator>(const Node& other) const {
            return (u + d) > (other.u + other.d);
        }
    };

public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // If the starting position is an obstacle, 0 cells are visited
        if (mat[r][c] == '#') return 0;

        // Track minimum moves used to reach each cell: {min_u, min_d}
        vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {1e9, 1e9}));

        // Min-heap Priority Queue
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        pq.push({r, c, 0, 0});
        vis[r][c] = {0, 0};

        int count = 0;

        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int cr = curr.r;
            int cc = curr.c;
            int cu = curr.u;
            int cd = curr.d;

            // If we've already found a strictly better path to this cell, skip
            if (cu > vis[cr][cc].first && cd > vis[cr][cc].second) continue;

            // Explore 4 adjacent directions
            for (int i = 0; i < 4; ++i) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                int nu = cu + (i == 0 ? 1 : 0); // Up move
                int nd = cd + (i == 1 ? 1 : 0); // Down move

                // Check boundaries, obstacle condition, and move constraints
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.' && nu <= u && nd <= d) {
                    if (nu < vis[nr][nc].first || nd < vis[nr][nc].second) {
                        // Update with minimum moves
                        if (nu < vis[nr][nc].first) vis[nr][nc].first = nu;
                        if (nd < vis[nr][nc].second) vis[nr][nc].second = nd;

                        pq.push({nr, nc, nu, nd});
                    }
                }
            }
        }

        // Count all visited (reachable) cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j].first != 1e9 || vis[i][j].second != 1e9) {
                    count++;
                }
            }
        }

        return count;
    }
};