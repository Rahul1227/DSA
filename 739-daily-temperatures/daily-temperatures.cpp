class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        int n = temp.size();
        stack<int> st;
        vector<int> result (n, 0);

        for(int i =0; i<n; i++){
            while(!st.empty() && temp[i] > temp[st.top()]){
                int ind = st.top();
                st.pop();
                result[ind] = i - ind;
            }
            st.push(i);
        }
        return result;
    }
};