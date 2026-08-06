static const int MOD = 1e9+7;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num : nums){
            pq.push(num);
        }

        while(k > 0){
            int ele = pq.top();
            pq.pop();
            int nextEle = (!pq.empty()) ? pq.top() : -1;
            if(nextEle != -1){
                int increment = nextEle - ele + 1;
                int allowed = min(increment, k);
                ele += allowed;
                k -= allowed;
                
            }else{
                ele++;
                k--;
                
            }
            pq.push(ele);
            
        }

        long long product = 1;
        while(!pq.empty()){
            product = (1LL * product * pq.top()) % MOD;
            pq.pop();
        }

        return product;
        
    }
};