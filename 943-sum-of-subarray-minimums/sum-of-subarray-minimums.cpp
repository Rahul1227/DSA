const int MOD = 1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long ans = 0LL;

        for(int i=0; i<=n; i++){
            int currVal = (i<n ? arr[i] : INT_MIN); 
            while(!st.empty() && currVal < arr[st.top()]){
                int currInd = st.top();
                st.pop();
                int nse = i;
                int pse = (!st.empty() ? st.top() : -1);
                int left = currInd - pse;
                // cout<<left<<endl;
                int right = nse - currInd;
                // cout<<right<<endl;
                ans = ans + (((1LL * left * right) % MOD) * arr[currInd])  % MOD;



            }

            st.push(i);
        }

        return ans % MOD;
        
    }
};