class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> seatBlocks;
        seatBlocks.push_back({2,3,4,5});
        seatBlocks.push_back({4,5,6,7});
        seatBlocks.push_back({6,7,8,9});

        unordered_map<int, int> mp;

        for(auto seats : reservedSeats){
            int row = seats[0];
            int col = seats[1];
            mp[row] = mp[row] | (1 << col);
        }

        int ans = (n - mp.size()) * 2;
        

        for(auto &[row, mask]: mp){
            bool prev = false;
            for(int i=0; i<3; i++){
                bool isValid = true;
                if(prev){
                    prev = false;
                    continue;
                }
                for(int j=0; j<4; j++){
                    if(mask & (1 << seatBlocks[i][j])){
                        isValid = false;
                        break;
                    }
                }
                if(isValid){
                    prev = true;
                    ans++;
                }
                // cout<<ans<<endl;

            }

        }

        return ans;
        
    }
};