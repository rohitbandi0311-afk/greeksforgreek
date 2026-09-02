class Solution {
public:
    int solve(int n, string s) {
        // Track status of each uppercase letter ('A' - 'Z')
        // 0: Unseen / not in cafe
        // 1: Currently using a computer
        // 2: Turned away due to no capacity
        vector<int> status(26, 0);

        int occupied = 0;
        int unassigned_count = 0;

        for (char c : s) {
            int idx = c - 'A';

            // First time seeing this customer (Arrival)
            if (status[idx] == 0) {
                if (occupied < n) {
                    status[idx] = 1; // Assign a computer
                    occupied++;
                } else {
                    status[idx] = 2; // No computer available
                    unassigned_count++;
                }
            } 
            // Second time seeing this customer (Departure)
            else {
                if (status[idx] == 1) {
                    occupied--; // Free up the computer
                }
                // If status[idx] == 2, they were already counted as rejected, 
                // so we just let them depart without freeing a computer.
            }
        }

        return unassigned_count;
    }
};