#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int countAlwaysFound(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        std::vector<int> leftMax(n);
        std::vector<int> rightMin(n);

        int currMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            currMax = std::max(currMax, arr[i]);
            leftMax[i] = currMax;
        }

        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            currMin = std::min(currMin, arr[i]);
            rightMin[i] = currMin;
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            bool greaterThanLeft = (i == 0 || arr[i] > leftMax[i - 1]);
            bool smallerThanRight = (i == n - 1 || arr[i] < rightMin[i + 1]);

            if (greaterThanLeft && smallerThanRight) {
                count++;
            }
        }

        return count;
    }
};