class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++){
            int count =0;
            int ele = i;
            while(ele){
                if(ele & 1){
                    count = count + 1;
                }
                ele = ele>>1;
            }
            result.push_back(count);
        }
        return result;
        
    }
};