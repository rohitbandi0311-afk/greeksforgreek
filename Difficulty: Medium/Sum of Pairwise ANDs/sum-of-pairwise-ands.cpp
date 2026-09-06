class Solution {
public:
    long long pairAndSum(vector<int>& arr) {
        long long totalSum = 0;
        int n = arr.size();

        // Iterate through all 32 bit positions
        for (int i = 0; i < 32; i++) {
            long long count = 0;

            // Count how many numbers have the i-th bit set
            for (int j = 0; j < n; j++) {
                if ((arr[j] >> i) & 1) {
                    count++;
                }
            }

            // Number of pairs with the i-th bit set is count choose 2
            long long pairs = (count * (count - 1)) / 2;

            // Add the contribution of this bit to the total sum
            totalSum += pairs * (1LL << i);
        }

        return totalSum;
    }
};