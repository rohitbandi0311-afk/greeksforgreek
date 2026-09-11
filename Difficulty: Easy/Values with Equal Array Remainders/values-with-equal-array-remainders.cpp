class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        
        // Check if all elements are equal
        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                allEqual = false;
                break;
            }
        }
        if (allEqual) return -1;
        
        // Compute the GCD of absolute differences between consecutive elements 
        // (or between all elements and the first element)
        int g = 0;
        for (int i = 1; i < n; i++) {
            g = std::gcd(g, abs(arr[i] - arr[0]));
        }
        
        // Count the number of divisors of g
        int count = 0;
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++; // i is a divisor
                if (i * i != g) {
                    count++; // g / i is also a divisor
                }
            }
        }
        
        return count;
    }
};