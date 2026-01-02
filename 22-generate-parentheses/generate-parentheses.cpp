class Solution {
private:
    bool isValid(string s){
        stack<char> st;
        for(auto c : s){
            if(c == '('){
                st.push(c);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.empty();
    }

    void solve(int openCount, int closeCount, string &curr, vector<string> &ans){
        // base case
        if(openCount == 0 && closeCount ==0 ){
            if(isValid(curr)){
                ans.push_back(curr);
                return;
            }else{
                return;
            }
        }

        // openTake;
        if(openCount){
            curr.push_back('(');
            solve(openCount-1, closeCount, curr, ans);
            curr.pop_back();
        }

        if(closeCount){
            curr.push_back(')');
            solve(openCount, closeCount-1, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        int openCount = n;
        int closeCount = n;
        solve(openCount, closeCount, curr, ans);
        return ans;
        
    }
};