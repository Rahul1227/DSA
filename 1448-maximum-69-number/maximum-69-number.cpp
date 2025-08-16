class Solution {
public:
    int maximum69Number (int num) {
        stack<int> st;
        // pushing the number into the stack
        while(num){
            int digit = num % 10;
            st.push(digit);
            num = num/10;
        }
        bool flag =true;
        int answer = 0;
        while(!st.empty()){
            int topElement = st.top();
            st.pop();
            if(topElement == 6 && flag){
                answer = answer*10 + 9;
                flag = false;
            }else {
                answer = answer * 10 + topElement;
            }
            
        }

        return answer;
        
    }
};