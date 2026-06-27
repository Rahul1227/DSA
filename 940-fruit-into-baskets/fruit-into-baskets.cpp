class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n =fruits.size();
        int maxfruits = 0;
        int i =0;
        int j =0;
        while(j<n){
            int type = fruits[j];
            mp[type]++;
            while(mp.size() > 2){
                // cout<<"maxSize: "<<mp.size()<<endl;
                int oldType = fruits[i];
                mp[oldType]--;
                if(mp[oldType] == 0){
                    mp.erase(oldType);
                }
                i++;

            }
            maxfruits = max(maxfruits, j-i+1);
            // cout<<maxfruits;
            j++;
        }

        return maxfruits;
        
    }
};