class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num: nums){
            pq.push(num);
        }

        long long score = 0;
        while(k--){
            int ele = pq.top();
            pq.pop();
            score = 1LL * score + ele;
            ele = ceil(1.00 * ele/3);
            pq.push(ele);
        }
        return score;
        
    }
};