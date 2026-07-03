class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int closing =0;
        for(auto c : s){
            if( c == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    closing++;
                }
            }else{
                st.push('(');
            }
            
        }

        return st.size() + closing;
        
    }
};