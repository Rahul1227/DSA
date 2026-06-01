class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int> pq;
        for(int num : cost){
            pq.push(num);
        }
        int ans = 0;
        while(!pq.empty()){
            int firstCost = pq.top();
            pq.pop();
            ans += firstCost;
            int secondCost = 0;
            if(!pq.empty()){
                secondCost += pq.top();
                pq.pop();
            }
            ans += secondCost;
            if(!pq.empty()){
                pq.pop();
            }
        }
        return ans;
        
    }
};