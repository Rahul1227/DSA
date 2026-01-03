class Solution {
    const int MOD = 1e9 + 7;
private:
    void generateFirstCol(string &curr, vector<string> &ans, char prev){
        // base case
        if(curr.size() == 3){
            ans.push_back(curr);
            return;
        }


        string colors = "RGB";

        for (auto c : colors){
            if(prev == '0' || c != prev){
                curr.push_back(c);
                generateFirstCol(curr, ans, c);
                curr.pop_back();
            }
        }
    }

    int solve(int row, int prevInd, vector<string> &firstCol, int n,vector<vector<int>> &dp){
        //base case
        if(row == n){
            return 1;
        }

        if(dp[row][prevInd] != -1) return dp[row][prevInd];

        string prevRow = firstCol[prevInd];
        int ans = 0;

        for(int i =0; i< firstCol.size(); i++){
            if(i == prevInd) continue;
            string currWord = firstCol[i];
            bool flag = false;
            for(int j =0; j<3; j++){
                if(prevRow[j] == currWord[j]){
                    flag = true;
                    break;
                }
            }

            if(!flag){
                ans = (ans + solve(row + 1, i, firstCol, n,dp)) % MOD;

            }
        }

        return dp[row][prevInd] = ans;
    }
public:
    int numOfWays(int n) {
        // generating the first col
        vector<string> firstCol;
        string curr= "";
        generateFirstCol(curr, firstCol, '0');
        // printing the firstCOl;
        // for(auto s: firstCol){
        //     cout<<s<<" ";
        // }

        vector<vector<int>> dp(n,vector<int>(13, -1));

        int ans = 0;

        for(int i =0; i< firstCol.size(); i++){
            ans = (ans + solve(1,i,firstCol,n, dp)) % MOD;
        }

        return ans;
        
    }
};