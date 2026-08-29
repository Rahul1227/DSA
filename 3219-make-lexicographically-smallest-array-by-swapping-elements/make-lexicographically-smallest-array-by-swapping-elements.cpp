class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        int n = nums.size();
        for(int i=0; i<n; i++){
            arr.push_back({nums[i],i});

        }

        sort(arr.begin(), arr.end());

        int rank = 0;
        unordered_map<int, vector<int>> mp;

        int i =0;
        while(i<n){
            auto[val, ind] = arr[i];
            nums[ind] = rank;
            mp[rank].push_back(val);
            int j;
            for(j=i+1; j<n; j++){
                if(arr[j].first - arr[j-1].first <= limit){
                    auto[val, ind] = arr[j];
                    nums[ind] = rank;
                    mp[rank].push_back(val);

                }else{
                    break;
                }
            }
            i = j;
            rank++;
        }

        // for(auto &[rank, val] : mp){
        //     sort(val.begin(), val.end());
        //     // cout<<rank<<" -> ";
        //     // for(auto num: val){
        //     //     cout<<num<<" ";
        //     // }
        //     // cout<<endl;
        // }

        vector<int> indices(rank,  0);
        for(int i=0; i<n; i++){
            int rank = nums[i];
            cout<<rank<<endl;
            nums[i] = mp[rank][indices[rank]];
            indices[rank]++;
        }

        return nums;
        
    }
};