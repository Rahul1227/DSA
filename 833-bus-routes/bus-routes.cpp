class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> busStopToBus;
        
        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size(); j++){
                busStopToBus[routes[i][j]].push_back(i);
            }
        }

        unordered_set<int> visited;
        
        queue<int> q;
        for(auto v : busStopToBus[source]){
            q.push(v);
            visited.insert(v);
        }

        int ans = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                int bus = q.front();
                q.pop();
                for(auto busStop : routes[bus]){
                    if(busStop == target) return ans;
                    for(auto v : busStopToBus[busStop]){
                        if(!visited.count(v)){
                            q.push(v);
                            visited.insert(v);
                        }
                    }
                }
            }
            ans++;

        }
        return -1;
        
    }
};