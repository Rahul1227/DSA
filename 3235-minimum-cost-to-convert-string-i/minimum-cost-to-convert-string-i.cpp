class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMat(26, vector<long long>(26, LLONG_MAX));

        // for(int i =0; i<26; i++){
        //     adjMat[i][i] = 0;
        // }

        for(int i =0; i< original.size(); i++){
            adjMat[original[i]-'a'][changed[i]-'a'] = min(adjMat[original[i]-'a'][changed[i]-'a'],(long long)  cost[i] );
        }

        // running floyd-warshall algo
        for(int k =0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j =0; j<26; j++){
                    if(adjMat[i][k] != LLONG_MAX && adjMat[k][j] != LLONG_MAX){
                        adjMat[i][j] = min(adjMat[i][j], 0LL+ adjMat[i][k] + adjMat[k][j]);
                    }
                }
            }
        }

        long long ans = 0;

        for(int i =0; i< source.size(); i++){
            if(source[i] != target[i]){
                long long currCost = adjMat[source[i]-'a'][target[i]-'a'];
                if(currCost == LLONG_MAX) return -1;
                else ans += currCost;
            }
        }
        return ans;
    }
};