class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.size();
        if(k == n){
            return "0";
        }
        for(int i =0; i<n; i++){
            while(!st.empty() && k && (num[i]-'0') < st.top()){
                st.pop();
                k--;

            }
            st.push(num[i] -'0');

        }

        while(!st.empty() && k--){
            st.pop();
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top() + '0';
            st.pop();
        }

        while(ans.size() > 0 && ans[ans.size()-1] =='0'){
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        if(ans.size() == 0){
            return "0";
        }
        return ans;
        
    }
};