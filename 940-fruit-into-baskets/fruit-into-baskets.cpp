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
                cout<<"maxSize: "<<mp.size()<<endl;
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
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