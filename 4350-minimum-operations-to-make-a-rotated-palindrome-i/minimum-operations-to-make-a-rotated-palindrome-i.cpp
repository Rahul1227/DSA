class Solution {
private:
    int getOps(deque<char> dq){
        int totalOps = 0;
        while(!dq.empty()){
            int firstInd = (dq.front() - 'a');
            dq.pop_front();
            int secondInd = firstInd;
            if(!dq.empty()){
                secondInd = dq.back() -'a';
                dq.pop_back();
            }
            int maxInd = max(firstInd, secondInd);
            int minInd = min(firstInd, secondInd);
            int currOps = min(maxInd-minInd, (25-maxInd) + minInd+1);
            totalOps += currOps;

        }

        return totalOps;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        deque<char> dq;
        for(auto c : s){
            dq.push_back(c);
        }
        int minOps = INT_MAX;

        for(int i=0; i<n; i++){
            int currOps = getOps(dq);
            int totalOps = currOps + i;
            minOps = min(minOps, totalOps);
            //rotating
            char c = dq.front();
            dq.pop_front();
            dq.push_back(c);

        }
        return minOps;
        
    }
};