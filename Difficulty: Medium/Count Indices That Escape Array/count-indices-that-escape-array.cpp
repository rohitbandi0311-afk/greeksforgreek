class Solution {
private:
    // Helper function with memoization:
    // 0: Unvisited
    // 1: Good (escapes array)
    // 2: Bad (trapped in cycle or dead end)
    int dfs(int curr, vector<int>& arr, vector<int>& memo) {
        int n = arr.size();

        // Base case: if it goes outside the array, it's good
        if (curr < 0 || curr >= n) {
            return 1; 
        }

        // If a zero is encountered, it's a dead end (bad)
        if (arr[curr] == 0) {
            return memo[curr] = 2;
        }

        // If already computed, return the cached result
        if (memo[curr] != 0) {
            return memo[curr];
        }

        // Mark current node as visiting (using 2 temporarily or a separate visited array to detect cycles)
        // Here we can use 2 temporarily to detect cycles during traversal
        memo[curr] = 2; 

        int next_idx = curr + arr[curr];

        // Recursively check the next jump
        int result = dfs(next_idx, arr, memo);

        // Save and return the final state for this index
        return memo[curr] = result;
    }

public:
    int goodIndices(vector<int>& arr) {
        int n = arr.size();
        vector<int> memo(n, 0); // 0 means unvisited
        int good_count = 0;

        for (int i = 0; i < n; ++i) {
            if (memo[i] == 0) {
                dfs(i, arr, memo);
            }
            if (memo[i] == 1) {
                good_count++;
            }
        }

        return good_count;
    }
};