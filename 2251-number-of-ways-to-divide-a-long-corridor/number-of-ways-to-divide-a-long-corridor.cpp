// class Solution {
//     const int MOD = 1e9 + 7;
// private:
//     bool isPossible(int i, int j, string &str){
//         int count =0;
//         for(int k=i; k<=j; k++){
//             if(str[k] == 'S') count++;
//         }

//         return count==2;
//     }
//     int solve(int ind,vector<int> &dp, string & str){
//         //base  case
//         if(ind == str.size()) return 1;
//         if(dp[ind] != -1) return dp[ind];
//         int totalway = 0;
//         for(int k =ind; k<str.size(); k++){
//             if(isPossible(ind,k,str)){
//                 totalway = (totalway + (solve(k+1, dp, str)) % MOD) % MOD;
//             }

//         }

//         return dp[ind] = totalway;
//     }
// public:
//     int numberOfWays(string corridor) {
//         int n = corridor.size();
//         vector<int> dp(n,-1);
//         return solve(0, dp, corridor);
        
//     }
// };

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        vector<int> seatPos; // positions of seats
        
        // Collect all seat positions
        for(int i = 0; i < corridor.size(); i++){
            if(corridor[i] == 'S') seatPos.push_back(i);
        }
        
        int totalSeats = seatPos.size();
        
        // Edge cases
        if(totalSeats == 0 || totalSeats % 2 != 0) return 0;
        if(totalSeats == 2) return 1;
        
        long long ways = 1;
        
        // Between each pair of sections (2nd seat and 3rd seat, 4th and 5th, etc.)
        // count the gap - this is the number of places we can put a divider
        for(int i = 2; i < totalSeats; i += 2){
            // Gap between the i-1 th seat (end of previous section) 
            // and i th seat (start of next section)
            int gap = seatPos[i] - seatPos[i-1];
            ways = (ways * gap) % MOD;
        }
        
        return ways;
    }
};