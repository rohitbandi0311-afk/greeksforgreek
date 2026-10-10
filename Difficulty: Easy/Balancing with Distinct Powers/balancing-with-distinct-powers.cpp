class Solution {
public:
    bool balancePan(int a, int b) {
        while (b > 0) {
            int rem = b % a;
            if (rem == 0) {
                b /= a;
            } else if (rem == 1) {
                b /= a;
            } else if (rem == a - 1) {
                b = (b + 1) / a;
            } else {
                return false;
            }
        }
        return true;
    }
};