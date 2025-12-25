class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int count =0;
        priority_queue<int> pq;
        int n = happiness.size();
        for(int i=0; i<n; i++){
            pq.push(happiness[i]);
        }

        while(k--){
            int topVal = pq.top() - count++;
            pq.pop();
            ans += topVal >=0 ? topVal : 0;

        }

        return ans;
        
    }
};