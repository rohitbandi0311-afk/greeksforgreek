#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        // Adjacency list: stores {neighbor, cost}
        // cost = 0 for original edge (u -> v)
        // cost = 1 for reversed edge (v -> u)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        // Distance array initialized to infinity
        vector<int> dist(n + 1, 1e9);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == dst) return dist[dst];

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    if (weight == 0) {
                        dq.push_front(v); // 0-cost edge goes to the front
                    } else {
                        dq.push_back(v);  // 1-cost edge goes to the back
                    }
                }
            }
        }

        // If destination is unreachable
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};