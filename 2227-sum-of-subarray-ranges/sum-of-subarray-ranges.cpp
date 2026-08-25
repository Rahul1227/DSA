class Solution {
private:
    long long sumOfMax(vector<int> &arr) {
        // code here
        stack<int> st;
        long long ans = 0;
        int n = arr.size();
        
        for(int i=0; i<=n; i++){
            int currEle = i < n ? arr[i] : INT_MAX;
            while(!st.empty() && currEle > arr[st.top()]){
                int currInd = st.top();
                st.pop();
                int ngeInd = i;
                int pgeInd = !st.empty() ? st.top() : -1;
                int leftContri = currInd - pgeInd;
                int rightContri = ngeInd - currInd;
                ans += 1LL * leftContri * rightContri * arr[currInd];
            }
            st.push(i);
        }
        
        // while(!st.empty()){
        //     int currInd = st.top();
        //     st.pop();
        //     int ngeInd = n;
        //     int pgeInd = !st.empty() ? st.top() : -1;
        //     int leftContri = currInd - pgeInd;
        //     int rightContri = ngeInd - currInd;
        //     ans += leftContri * rightContri * arr[currInd];
        // }
        
        return ans;
    
        
    }


    long long sumOfMin(vector<int>& arr) {
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
                long long currSum = 1LL * arr[currInd] * leftCount * rightCount;
                totalSum = 1LL * totalSum + currSum;
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
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMax(nums) - sumOfMin(nums);
        
    }
};