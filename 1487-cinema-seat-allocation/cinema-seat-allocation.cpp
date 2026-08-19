class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0;
        int mid = 0;
        int right = 0;

        for(int i=2; i<=5; i++){
            left = left | (1<<i);
        }

        for(int i=4; i<=7; i++){
            mid = mid | (1 << i);
        }

        for(int i=6; i<=9; i++){
            right = right | (1<<i);
        }

        unordered_map<int, int> mp;

        for(auto seats : reservedSeats){
            int row = seats[0];
            int col = seats[1];
            mp[row] = mp[row] | (1 << col);
        }

        int ans = (n - mp.size()) * 2;
        

        for(auto &[row, mask]: mp){
            bool l = !(mask & left);
            bool r = !(mask & right);
            bool m = !(mask &mid);

            if(l && r){
                ans += 2;
            }else if(l || r || m){
                ans++;
            }

        }

        return ans;
        
    }
};