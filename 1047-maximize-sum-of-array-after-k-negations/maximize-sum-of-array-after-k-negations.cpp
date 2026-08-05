class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num : nums){
            pq.push(num);
        }

        while(k--){
            int ele = pq.top();
            pq.pop();
            ele = -ele;
            pq.push(ele);
            // k--;
        }

        int totalSum =0;

        while(!pq.empty()){
            totalSum += pq.top();
            pq.pop();
        }
        return totalSum;
        
    }
};