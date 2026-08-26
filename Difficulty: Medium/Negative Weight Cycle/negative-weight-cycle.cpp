class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> dist(n, 1e8);
        dist[0] = 0;

        // Relax all edges (V - 1) times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles (V-th iteration)
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return 1; // Negative weight cycle exists
            }
        }

        return 0; // No negative weight cycle
    }
};