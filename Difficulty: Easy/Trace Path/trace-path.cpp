class Solution {
public:
    bool isPossible(int n, int m, string &s) {
        int curr_x = 0, curr_y = 0;
        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;

        for (char ch : s) {
            if (ch == 'L') {
                curr_y--;
            } else if (ch == 'R') {
                curr_y++;
            } else if (ch == 'D') {
                curr_x--; // Move one cell up/decrement row depending on indexing, let's follow problem directions: D: (i-1, j), U: (i+1, j)
            } else if (ch == 'U') {
                curr_x++;
            }

            min_x = min(min_x, curr_x);
            max_x = max(max_x, curr_x);
            min_y = min(min_y, curr_y);
            max_y = max(max_y, curr_y);
        }

        int rows_needed = max_x - min_x + 1;
        int cols_needed = max_y - min_y + 1;

        if (rows_needed <= n && cols_needed <= m) {
            return true;
        }
        return false;
    }
};