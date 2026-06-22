class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> tree(n);
        vector<long long> computed(n,0);
        for(int i=0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            tree[u].push_back(v);
        }

        for(int i = n-1; i>=0; i--){
            if(tree[i].size() == 0){
                computed[i] = baseTime[i];
            }else if(tree[i].size() == 1){
                computed[i] = baseTime[i] + computed[tree[i][0]];
            }else{
                long long earliest = computed[tree[i][0]];
                long long lastest = computed[tree[i][0]];
                for(int j=1; j< tree[i].size(); j++){
                    earliest = min(earliest, computed[tree[i][j]]);
                    lastest = max(lastest, computed[tree[i][j]]);
                }
                long long ownDuration  = (lastest - earliest) + baseTime[i];
                computed[i] = ownDuration + lastest;
            }
        }
        // for(int i =0; i<n; i++){
        //     cout<<computed[i]<<endl;
        // }
        return computed[0];
        
    }
};