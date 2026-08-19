class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto num : nums){
            pq.push(num);
        }

        while(!pq.empty()){
            int topEle = pq.top();
            pq.pop();
            if(pq.empty() || topEle != pq.top()) continue;
            vector<int> currEq;
            while(!pq.empty() && topEle == pq.top()){
                currEq.push_back(topEle);
                pq.pop();
            }

            // int counter = 1;
            for(int i=0; i<currEq.size(); i++){
                ans += i+1;
                pq.push(currEq[i] + i+1);
            }
        }

        return ans;
        
    }
};