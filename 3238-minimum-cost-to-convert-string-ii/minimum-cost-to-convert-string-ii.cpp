using pii = pair<int,int>;
using ll = long long;
class Solution {
private:
    //  solve(0, source, target, validLen, dp, adj);
    ll solve(int ind, string &source, string &target, set<int> &validLen, vector<ll> &dp, vector<vector<ll>> &adj, unordered_map<string,int> &stringToId){
        //base case
        if(ind == source.size()){
            return 0;
        }

        if(dp[ind] != -1) return dp[ind];

        ll ans = LLONG_MAX;
        if(source[ind] == target[ind]){
            ans = min(ans,solve(ind+1, source, target, validLen, dp, adj, stringToId)) ;
        }

        // ll noTake = LLONG_MAX;
        for(auto len : validLen){
            if(ind + len > source.size()) break;
            string sourceStr = source.substr(ind, len);
            string targetStr = target.substr(ind, len);
            if(!stringToId.count(sourceStr) || !stringToId.count(targetStr)) continue;
            int ind1 = stringToId[sourceStr];
            int ind2 = stringToId[targetStr];
            if(adj[ind1][ind2] >= INT_MAX) continue;
            ll subCall = solve(ind+len,source, target, validLen,dp, adj,stringToId);
            if(subCall >= LLONG_MAX) continue;
            ans = min(ans, 1LL *adj[ind1][ind2] + subCall);
            

        }

        return dp[ind] = ans;

    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> stringToId;
        int idCounter = 0;

        for(auto str: original){
            if(!stringToId.count(str)){
                stringToId[str] = idCounter++;
            }
        }

        for(auto str: changed){
            if(!stringToId.count(str)){
                stringToId[str] = idCounter++;
            }
        }

        vector<vector<ll>> adj(idCounter, vector<ll>(idCounter, INT_MAX));
        // pushing 0 on the diagonal
        for(int i=0; i<idCounter; i++){
            adj[i][i] = 0;
        }

        for(int i=0; i<original.size(); i++){
            int u = stringToId[original[i]];
            int v = stringToId[changed[i]];
            int w = cost[i];
            adj[u][v] = min(adj[u][v], 1LL *w);
        }

        for(int k=0; k<idCounter; k++){
            for(int i=0; i<idCounter; i++){
                for(int j=0; j<idCounter; j++){
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }

                }
            }
        }

        set<int> validLen;
        for(auto str: original){
            validLen.insert(str.size());
        }

        int n = source.size();
        vector<ll> dp(n+1, -1);
        ll result = solve(0, source, target, validLen, dp, adj, stringToId);
        if(result >= LLONG_MAX) return -1;
        return result;

        
    }
};