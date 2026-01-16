class Solution {
    const int MOD = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        // sort(hFences.begin(), hFences.end());

        vFences.push_back(1);
        vFences.push_back(n);
        // sort(vFences.begin(), vFences.end());

        unordered_set<int> st;
        int n1 = hFences.size();
        int n2 = vFences.size();


        for(int i = 0; i< n1; i++){
            for(int j = i+1; j<n1; j++){
                int diff = abs(hFences[i] - hFences[j]);
                st.insert(diff);

            }
        }

        int maxSide = -1;
        for(int i=0; i<n2; i++){
            for(int j=i+1; j<n2; j++){
                int diff = abs(vFences[i] - vFences[j]);
                if(st.count(diff)){
                    maxSide = max(maxSide, diff);
                }
            }
        }

        if(maxSide == -1) return -1;

        long long area = maxSide *1LL * maxSide;
        return area % MOD;

        
        

        
    }
};