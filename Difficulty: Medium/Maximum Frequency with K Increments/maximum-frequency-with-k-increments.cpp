class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        long long l = 0, ans = 1, current_sum = 0;

        for (long long r = 0; r < arr.size(); ++r) {
            current_sum += arr[r];

            // Check if operations required to make all elements in arr[l...r] equal to arr[r] exceeds k
            while ((r - l + 1) * arr[r] - current_sum > k) {
                current_sum -= arr[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};