class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> st;
        int n = boxes.size();
        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                st.insert(i);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            int temp =0;
            for(auto ind : st){
                // cout<<ind<<endl;
                temp += abs(i - ind);

            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};