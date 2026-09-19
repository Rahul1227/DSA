class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        int elementsInStack = 0LL;
        stack<pair<int,int>> st;
        
        for(auto num: nums){
            // poping the greater
            int poppedElements = 0;
            while(!st.empty() && st.top().first > num){
                poppedElements += st.top().second;
                st.pop();
            }

            elementsInStack -= poppedElements;

            // case 1-> the curr element is greater
            if(!st.empty() && st.top().first < num || st.empty()){
                ans += elementsInStack;
                elementsInStack++;
                st.push({num, 1});
            }else if(!st.empty() && st.top().first == num){
                ans += elementsInStack - st.top().second;
                elementsInStack++;
                st.top().second++;
            }
        }

        return ans;
        
    }
};