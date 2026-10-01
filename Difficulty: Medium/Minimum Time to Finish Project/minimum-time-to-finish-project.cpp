class Solution {
public:
    int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {
        int n = duration.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        // Build the graph and calculate in-degrees
        for (const auto& dep : dependencies) {
            int u = dep[0];
            int v = dep[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        vector<int> startTime(n, 0);

        // Push nodes with 0 in-degree into the queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int processedCount = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processedCount++;

            for (int v : adj[u]) {
                // Update the earliest start time for the dependent module
                startTime[v] = max(startTime[v], startTime[u] + duration[u]);

                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If there is a cycle, we cannot complete the project
        if (processedCount != n) {
            return -1;
        }

        // Find the maximum completion time across all modules
        int totalTime = 0;
        for (int i = 0; i < n; i++) {
            totalTime = max(totalTime, startTime[i] + duration[i]);
        }

        return totalTime;
    }
};