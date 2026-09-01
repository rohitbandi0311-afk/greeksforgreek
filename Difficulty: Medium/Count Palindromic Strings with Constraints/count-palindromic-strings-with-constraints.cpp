class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total_count = 0;

        for (int len = 1; len <= n; ++len) {
            int m = len / 2;
            int distinct_needed = (len % 2 == 0) ? m : m + 1;

            if (distinct_needed > k) {
                continue; // Impossible to form a valid palindrome of this length
            }

            // Calculate Permutation P(k, distinct_needed) % MOD
            long long ways = 1;
            for (int i = 0; i < distinct_needed; ++i) {
                ways = (ways * (k - i)) % MOD;
            }

            total_count = (total_count + ways) % MOD;
        }

        return total_count;
    }
};