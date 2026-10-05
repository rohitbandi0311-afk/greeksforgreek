class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<vector<int>> result;

        // Process users i from 2 to n
        for (int i = 2; i <= n; ++i) {
            // Map to store the distance from user i to all reachable users
            unordered_map<int, int> reachable;

            int curr = i;
            int dist = 0;

            // Traverse upwards following the friend links
            while (curr > 1) {
                int friendUser = arr[curr - 2];
                dist++;
                reachable[friendUser] = dist;
                curr = friendUser;
            }

            // For each user i, consider users j from 1 to i - 1 in increasing order
            for (int j = 1; j < i; ++j) {
                if (reachable.find(j) != reachable.end()) {
                    result.push_back({i, j, reachable[j]});
                }
            }
        }

        return result;
    }
};