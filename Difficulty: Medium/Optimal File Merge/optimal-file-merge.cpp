#include <vector>
#include <queue>

class Solution {
public:
    int minComputation(std::vector<int>& files) {
        // Create a min-heap to store the file sizes
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(
            files.begin(), files.end()
        );

        int totalCost = 0;

        // Continue merging until only one file is left
        while (minHeap.size() > 1) {
            // Extract the two smallest files
            int first = minHeap.top();
            minHeap.pop();

            int second = minHeap.top();
            minHeap.pop();

            // Cost to merge these two files
            int mergeCost = first + second;
            totalCost += mergeCost;

            // Push the newly merged file back into the heap
            minHeap.push(mergeCost);
        }

        return totalCost;
    }
};