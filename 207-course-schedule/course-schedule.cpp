class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> ans;

        for(int i =0;  i< prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i =0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n; i++){
                int u = q.front();
                q.pop();
                ans.push_back(u);

                for(auto v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }

            }
        }

        return ans.size() == numCourses;

        
    }
};