#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubsquare(std::vector<std::vector<char>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // hor[i][j] stores consecutive 'X's to the left including (i, j)
        // ver[i][j] stores consecutive 'X's upwards including (i, j)
        std::vector<std::vector<int>> hor(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> ver(n, std::vector<int>(n, 0));

        int maxSide = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'X') {
                    hor[i][j] = (j == 0) ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = (i == 0) ? 1 : ver[i - 1][j] + 1;
                } else {
                    hor[i][j] = 0;
                    ver[i][j] = 0;
                }
            }
        }

        // Check all cells as the bottom-right corner of a square
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Find the maximum possible side length based on current cell's available 'X' counts
                int small = std::min(hor[i][j], ver[i][j]);

                // Greedily check smaller side lengths if current 'small' is greater than maxSide
                while (small > maxSide) {
                    // Check top edge and left edge of the square of size 'small'
                    // Top-left corner will be at (i - small + 1, j - small + 1)
                    if (ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small) {
                        maxSide = std::max(maxSide, small);
                        break;
                    }
                    small--;
                }
            }
        }

        return maxSide;
    }
};