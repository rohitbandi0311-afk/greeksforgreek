class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        n*=4;
        vector<vector<int>>mat(n,vector<int>(n,0));
        vector<vector<int>>ans(2);
        int a = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = a;
                a++;
            }
        }

        int top = 0;
        int left = 0;
        int down = n-1;
        int right = n-1;
        int flag = 1;

        while(top<down && left<right){
            // top to down
            for(int k=top;k<down;k++) ans[!flag].push_back(mat[k][left]);
            // left to right
            for(int k=left;k<right;k++) ans[!flag].push_back(mat[down][k]);
            // down to top
            for(int k=down;k>top;k--) ans[flag].push_back(mat[k][right]);
            // right to left
            for(int k=right;k>left;k--) ans[flag].push_back(mat[top][k]);

            top++;
            left++;
            down--;
            right--;
            flag = (!flag); // to switch color of all for loop for next iteration
        }

        return ans;
    }
};