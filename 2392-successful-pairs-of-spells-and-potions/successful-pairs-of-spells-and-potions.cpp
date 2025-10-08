class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result(n,0);
        for(int i =0; i<n; i++){
            // for(int j =0; j<m; j++){
            //     long long product =(long long)spells[i] * potions[j];
            //     if(product >= success){
            //         result[i] = m-j;
            //         break;
            //     }
            // }

            // this part is giving tle. so binary search should be used.

            int firstEle = spells[i];
            double tofind = (double)success/firstEle;
            auto it = lower_bound(potions.begin(), potions.end(),tofind);
            int ind = it - potions.begin();
            result[i] = m-ind;

            
        }
        return result;
        
    }
};