class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();

        // All 8 possible directions: (row_dir, col_dir)
        int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        set<vector<int>> result; // To store unique starting positions

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, check all 8 directions
                if (mat[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        int k, curr_x = i, curr_y = j;

                        // Traverse along the chosen direction
                        for (k = 0; k < len; k++) {
                            // Check bounds
                            if (curr_x < 0 || curr_x >= n || curr_y < 0 || curr_y >= m)
                                break;

                            // Check character match
                            if (mat[curr_x][curr_y] != word[k])
                                break;

                            // Move to the next cell in the same direction
                            curr_x += x[dir];
                            curr_y += y[dir];
                        }

                        // If we matched the entire word, add the starting point
                        if (k == len) {
                            result.insert({i, j});
                            break; // Once found from this cell, no need to check other directions for this cell
                        }
                    }
                }
            }
        }

        // Convert set to vector for the final output
        return vector<vector<int>>(result.begin(), result.end());
    }
};