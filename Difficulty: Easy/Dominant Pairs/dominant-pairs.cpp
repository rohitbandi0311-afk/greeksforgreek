#include <vector>
#include <algorithm>

class Solution {
public:
    int dominantPairs(std::vector<int>& arr) {
        int n = arr.size();
        int mid = n / 2;

        // Sort the first half and the second half
        std::sort(arr.begin(), arr.begin() + mid);
        std::sort(arr.begin() + mid, arr.end());

        int count = 0;
        int j = mid;

        // For each element in the first half, find valid elements in the second half
        for (int i = 0; i < mid; ++i) {
            // We want arr[i] >= 5 * arr[j]
            // Which is equivalent to arr[j] <= arr[i] / 5
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            // All elements in the second half from 'mid' up to 'j - 1' satisfy the condition
            count += (j - mid);
        }

        return count;
    }
};