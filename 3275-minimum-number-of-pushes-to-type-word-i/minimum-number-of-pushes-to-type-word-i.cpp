class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int counter = 1;
        for(int i=0; i< word.size(); i++){
            ans += ceil(1.0000 * counter/8);
            counter++;
            
        }

        return ans;
        
    }
};