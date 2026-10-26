class Solution {
public:
    int minDiff(int k, vector<int>& arr) {
        int n = arr.size();

        // prefMin[i] and prefMax[i] store min and max from index 0 to i
        vector<int> prefMin(n), prefMax(n);
        prefMin[0] = arr[0];
        prefMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefMin[i] = min(prefMin[i - 1], arr[i]);
            prefMax[i] = max(prefMax[i - 1], arr[i]);
        }

        // suffMin[i] and suffMax[i] store min and max from index i to n - 1
        vector<int> suffMin(n), suffMax(n);
        suffMin[n - 1] = arr[n - 1];
        suffMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], arr[i]);
            suffMax[i] = max(suffMax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        // Try removing every possible subarray of size k from index i to i + k - 1
        for (int i = 0; i <= n - k; i++) {
            int currentMin = INT_MAX, currentMax = INT_MIN;

            // If there is a valid prefix left before the removed subarray
            if (i > 0) {
                currentMin = min(currentMin, prefMin[i - 1]);
                currentMax = max(currentMax, prefMax[i - 1]);
            }

            // If there is a valid suffix left after the removed subarray
            if (i + k < n) {
                currentMin = min(currentMin, suffMin[i + k]);
                currentMax = max(currentMax, suffMax[i + k]);
            }

            ans = min(ans, currentMax - currentMin);
        }

        return ans;
    }
};