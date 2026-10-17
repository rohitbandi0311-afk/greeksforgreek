class Solution {
public:
    bool isItPossible(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        // If lengths differ, conversion is impossible
        if (n != m) return false;

        int i = 0, j = 0;

        while (i < n && j < n) {
            // Skip '#' in s1
            while (i < n && s1[i] == '#') {
                i++;
            }
            // Skip '#' in s2
            while (j < n && s2[j] == '#') {
                j++;
            }

            // If both reach the end
            if (i == n && j == n) return true;

            // If one reaches the end before the other
            if (i == n || j == n) return false;

            // Characters must match
            if (s1[i] != s2[j]) return false;

            // Check movement constraints
            if (s1[i] == 'A') {
                // 'A' can only move left (s1 index >= s2 index)
                if (i < j) return false;
            } else if (s1[i] == 'B') {
                // 'B' can only move right (s1 index <= s2 index)
                if (i > j) return false;
            }

            i++;
            j++;
        }

        // Skip any trailing '#' characters
        while (i < n && s1[i] == '#') i++;
        while (j < n && s2[j] == '#') j++;

        return i == n && j == n;
    }
};