#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        for (int x : arr) totalSum += x;

        vector<long long> left(n), right(n);

        // Left pass: Ensure left[i] <= left[i-1] + 1
        long long h = 0;
        for (int i = 0; i < n; ++i) {
            h = min((long long)arr[i], h + 1);
            left[i] = h;
        }

        // Right pass: Ensure right[i] <= right[i+1] + 1
        h = 0;
        for (int i = n - 1; i >= 0; --i) {
            h = min((long long)arr[i], h + 1);
            right[i] = h;
        }

        // Find the peak that gives the maximum total pyramid sum
        long long maxPyramidSum = 0;
        for (int i = 0; i < n; ++i) {
            long long currentPyramidSum = min(left[i], right[i]);
            maxPyramidSum = max(maxPyramidSum, currentPyramidSum);
        }

        // Wait, a standard pyramid allows heights 1, 2, ..., x, ..., 2, 1.
        // Let's refine the pass to build full triangles (h, h-1, ...)
        vector<long long> l(n), r(n);
        
        long long cur = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] < cur + 1) {
                cur = arr[i];
            } else {
                cur++;
            }
            l[i] = cur;
        }

        cur = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(arr[i] < cur + 1) {
                cur = arr[i];
            } else {
                cur++;
            }
            r[i] = cur;
        }

        long long maxSum = 0;
        for(int i = 0; i < n; ++i) {
            maxSum = max(maxSum, min(l[i], r[i]));
        }

        // The sum of elements in a pyramid of peak height H is H * H
        // Let's compute the exact maximum sum of the valid pyramid profile.
        long long bestPyramidElementsSum = 0;
        for(int i = 0; i < n; ++i) {
            long long H = min(l[i], r[i]);
            // The sum of a sequence 1, 2, ..., H, ..., 1 is H * H
            bestPyramidElementsSum = max(bestPyramidElementsSum, H * H);
        }

        return totalSum - bestPyramidElementsSum;
    }
};