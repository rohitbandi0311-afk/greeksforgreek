class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        // Concatenate string with itself to account for all rotations
        string doubled = s + s;

        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            char c1 = doubled[i + k];
            char c2 = doubled[j + k];

            if (c1 == c2) {
                k++;
            } else if (c1 > c2) {
                i = i + k + 1;
                if (i <= j) i = j + 1;
                k = 0;
            } else {
                j = j + k + 1;
                if (j <= i) j = i + 1;
                k = 0;
            }
        }

        int startIdx = (i < n) ? i : j;
        return s.substr(startIdx, n) + s.substr(0, startIdx); // Alternatively: return doubled.substr(startIdx, n);
    }
};