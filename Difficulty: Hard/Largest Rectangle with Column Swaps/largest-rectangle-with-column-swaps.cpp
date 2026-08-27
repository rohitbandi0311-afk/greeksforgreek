class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Calculate consecutive 1s vertically for each cell
        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; ++i) {
                if (mat[i][j] == 1) {
                    hist[i][j] = hist[i - 1][j] + 1;
                } else {
                    hist[i][j] = 0;
                }
            }
        }

        int max_area = 0;

        // Step 2: Sort heights row by row and calculate max rectangle area
        for (int i = 0; i < n; ++i) {
            vector<int> count = hist[i];
            sort(count.begin(), count.end(), greater<int>());

            for (int k = 0; k < m; ++k) {
                int curr_area = (k + 1) * count[k];
                max_area = max(max_area, curr_area);
            }
        }

        return max_area;
    }
};