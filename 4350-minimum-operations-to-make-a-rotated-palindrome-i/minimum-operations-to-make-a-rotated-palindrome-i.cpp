class Solution {
private:
    int getOps(string &s){
        int totalOps = 0;
        int i =0;
        int j = s.size()-1;
        while(i<j){
            int firstInd = s[i] -'a';
            int secondInd = s[j] -'a';
            int maxInd = max(firstInd, secondInd);
            int minInd = min(firstInd, secondInd);
            int currOps = min(maxInd-minInd, (25-maxInd) + minInd+1);
            totalOps += currOps;
            i++;
            j--;

        }

        return totalOps;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        
        int minOps = INT_MAX;

        for(int i=0; i<n; i++){
            int currOps = getOps(s);
            int totalOps = currOps + i;
            minOps = min(minOps, totalOps);
            //rotating
            rotate(s.begin(), s.begin()+1, s.end());

        }
        return minOps;
        
    }
};