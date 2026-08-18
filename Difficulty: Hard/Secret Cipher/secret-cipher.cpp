class Solution {
  public:
    string compress(string &s) {
        int n=s.length();

        int right=n-1;

        stack<char> st;
        while(right>=0)
        {
            int len=right+1;
            if(len%2==1)
            {
                st.push(s[right]);
                right--;
                continue;
            }
            int mid=right/2;

            string first=s.substr(0,len/2);
            string second=s.substr(mid+1,len/2);

            if(first==second)
            {
                st.push('*');
                right=mid;
            }
            else
            {
                st.push(s[right]);
                right--;
            }
        }

        string ans;

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
}; 

