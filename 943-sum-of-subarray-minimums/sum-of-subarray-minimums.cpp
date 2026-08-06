static const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // 2 pass solution is easy
        // get pse
        // get nse
        // left count = i- pse(i)
        // right count = i+ nse[i];
        // sum += leftCount * rightCount * ar[i];

        stack<int> st;
        int n = arr.size();
        long long totalSum = 0;
        for(int i =0; i<=n; i++){
            int currEle = (i==n) ? INT_MIN: arr[i];
            while(!st.empty() && currEle < arr[st.top()]){
                int currInd = st.top();
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                int nse = i;
                int leftCount = currInd - pse;
                int rightCount = nse - currInd;
                long long currSum = (1LL * arr[currInd] * leftCount * rightCount) % MOD;
                totalSum = (1LL * totalSum + currSum) % MOD;
            }
            st.push(i);
        }

        // while(!st.empty()){
        //     int currInd = st.top();
        //     st.pop();
        //     int pse = !st.empty() ? st.top() : -1;
        //     int nse = n;
        //     int leftCount = currInd - pse;
        //     int rightCount = nse - currInd;
        //     long long currSum = (1LL * arr[currInd] * leftCount * rightCount) % MOD;
        //     totalSum = (1LL * totalSum + currSum) % MOD;

        // }

        return totalSum;
        
    }
};