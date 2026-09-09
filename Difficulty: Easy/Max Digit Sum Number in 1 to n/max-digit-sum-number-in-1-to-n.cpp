class Solution {
public:
    long long findMax(long long n) {
        long long ans = n;
        long long max_sum = getDigitSum(n);

        long long p = 1;
        while (p <= n) {
            long long candidate = (n / (p * 10)) * (p * 10) + (p - 1);
            if (candidate > 0 && candidate <= n) {
                long long current_sum = getDigitSum(candidate);
                if (current_sum > max_sum || (current_sum == max_sum && candidate > ans)) {
                    max_sum = current_sum;
                    ans = candidate;
                }
            }

            // Also test decrementing the prefix digits further to catch cases like 7 -> 6 followed by 9s
            long long prefix_candidate = (n / (p * 10) - 1) * (p * 10) + (p * 10 - 1);
            if (prefix_candidate > 0 && prefix_candidate <= n) {
                long long current_sum = getDigitSum(prefix_candidate);
                if (current_sum > max_sum || (current_sum == max_sum && prefix_candidate > ans)) {
                    max_sum = current_sum;
                    ans = prefix_candidate;
                }
            }

            if (n / 10 < p) break;
            p *= 10;
        }

        return ans;
    }

private:
    long long getDigitSum(long long num) {
        long long sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};