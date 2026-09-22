#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    bool isSubsequence(const std::string& s, const std::string& word) {
        int i = 0, j = 0;
        int n = s.length(), m = word.length();

        while (i < n && j < m) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }

public:
    std::string findLongestWord(std::string& s, std::vector<std::string>& d) {
        // Sort dictionary: longer words first, then lexicographically smaller words
        std::sort(d.begin(), d.end(), [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
        });

        for (const std::string& word : d) {
            if (isSubsequence(s, word)) {
                return word; // The first valid word is guaranteed to be the optimal one
            }
        }

        return "";
    }
};