class Solution {
  public:
  int countSubarrayGreaterK(vector<int>&arr,int k)
  {
      int sum = 0;
      int i = 0,j = 0,n = arr.size();
      int count = 0;
      while(j<n)
      {
          sum = sum + arr[j];
          while(sum>k)
          {
              count = count + (n-j);
              sum = sum - arr[i];
              i++;
          }
          j++;
      }
      return count;
  }

    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int x = countSubarrayGreaterK(arr,r);
        int y = countSubarrayGreaterK(arr,l-1);
        return y - x;
        
    }
};

