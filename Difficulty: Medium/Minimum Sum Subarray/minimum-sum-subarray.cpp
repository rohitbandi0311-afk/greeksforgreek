class Solution {
public:
    int minSubarraySum(vector<int>& arr) {
        int min_so_far = arr[0];
        int current_min = arr[0];

        for (size_t i = 1; i < arr.size(); i++) {
            // Decide whether to add the current element to the existing subarray 
            // or start a new subarray from the current element.
            current_min = min(arr[i], current_min + arr[i]);

            // Update the overall minimum sum found so far.
            min_so_far = min(min_so_far, current_min);
        }

        return min_so_far;
    }
};