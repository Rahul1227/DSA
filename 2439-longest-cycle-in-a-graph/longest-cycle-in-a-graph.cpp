class Solution {
private:
    void getLongestCycle(int ind, vector<int> &visited, vector<int> &pathVisited,
                            vector<int> &currPath, vector<int> &edges, int &longestLen){
        
        visited[ind] =1;
        pathVisited[ind] = 1;
        currPath.push_back(ind);

        int v = edges[ind];
        if(v != -1){
            if(!visited[v]){
                getLongestCycle(v, visited, pathVisited, currPath, edges, longestLen);
            }else if(pathVisited[v]){
                vector<int> cycle;
                int startInd = -1;
                for(int i =0; i< currPath.size(); i++){
                    if(currPath[i] == v){
                        startInd = i;
                        break;
                    }

                }

                for(int i = startInd; i<currPath.size(); i++){
                    cycle.push_back(currPath[i]);
                }


                if((int)cycle.size() > longestLen){
                    longestLen = cycle.size();
                }
            }
        }

        pathVisited[ind] = 0;
        currPath.pop_back();
        
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> currPath;
        int longestLen = -1;
        for(int i =0; i<n; i++){
            if(!visited[i]){
                getLongestCycle(i, visited, pathVisited, currPath, edges, longestLen);
            }
        }

        return longestLen;

        
    }
};