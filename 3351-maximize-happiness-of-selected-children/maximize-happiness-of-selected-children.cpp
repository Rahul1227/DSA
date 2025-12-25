class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        make_heap(happiness.begin(), happiness.end());
        long long ans = 0;
        int count =0;
        while(k--){
            int topElement = happiness.front() - count++;
            pop_heap(happiness.begin(), happiness.end());
            happiness.pop_back();
            ans += topElement >= 0 ? topElement : 0;

        }

        return ans;
        
    }
};