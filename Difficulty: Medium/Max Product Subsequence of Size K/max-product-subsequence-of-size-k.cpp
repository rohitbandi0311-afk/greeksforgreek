class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long product = 1;
        int left = 0, right = n - 1;

        // If k is odd and all numbers are negative, picking the largest element 
        // will result in a heavily negative number. Instead, pick the smallest 
        // absolute values (from the end of the sorted array) to maximize the product.
        if (k % 2 != 0) {
            if (arr[right] < 0) {
                // Pick from the end (least negative numbers)
                for (int i = 0; i < k; i++) {
                    product *= arr[right--];
                }
                return product;
            } else {
                product = arr[right];
                right--;
                k--;
            }
        }

        // Pick elements in pairs from both ends for remaining even k
        while (k > 0) {
            long long prod1 = (long long)arr[left] * arr[left + 1];
            long long prod2 = (long long)arr[right] * arr[right - 1];

            if (prod1 > prod2) {
                product *= prod1;
                left += 2;
            } else {
                product *= prod2;
                right -= 2;
            }
            k -= 2;
        }

        return product;
    }
};