class Solution {
public:
    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0) {
            return 0;
        }

        int count = 0;
        long long product = (long long)x * y;

        // Iterate through divisors up to sqrt(product)
        for (long long i = 1; i * i <= product; i++) {
            if (product % i == 0) {
                long long j = product / i;

                // Check if gcd(i, j) == x and lcm(i, j) == y
                if (std::gcd(i, j) == x && (i / x) * (j / x) * x == y) { // Simplified LCM check: (i*j)/gcd == y -> product/x == y
                    // Since product = x * y, the LCM condition is automatically satisfied 
                    // if GCD(i, j) == x holds true.
                    if (i == j) {
                        count += 1;
                    } else {
                        count += 2;
                    }
                }
            }
        }

        return count;
    }
};