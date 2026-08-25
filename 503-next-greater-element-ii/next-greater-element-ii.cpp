class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i =0; i<2*n; i++){
            int actInd = i % n;

            while(!st.empty() && nums[st.top() % n] < nums[actInd]){
                int currInd = st.top();
                st.pop();
                if(currInd >= n) continue;
                ans[currInd] = nums[actInd];
            }
            st.push(i);

        }

        return ans;
    }
};