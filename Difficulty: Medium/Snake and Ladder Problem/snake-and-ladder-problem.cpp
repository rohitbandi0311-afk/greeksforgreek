#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;
        vector<int> moves(target + 1, -1);

        // Map ladders
        for (int i = 0; i < lad.size(); i += 2) {
            moves[lad[i]] = lad[i + 1];
        }

        // Map snakes
        for (int i = 0; i < sn.size(); i += 2) {
            moves[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(target + 1, false);
        queue<pair<int, int>> q; // {cell, throws}

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == target) return dist;

            for (int dice = 1; dice <= 6; ++dice) {
                int nextCell = curr + dice;

                if (nextCell <= target) {
                    // Check if there's a snake or ladder jump
                    if (moves[nextCell] != -1) {
                        nextCell = moves[nextCell];
                    }

                    if (!visited[nextCell]) {
                        visited[nextCell] = true;
                        q.push({nextCell, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};