class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    if (blocked.empty()) return true;
    
    int maxEnclosed = blocked.size() * (blocked.size() - 1) / 2;
    
    set<pair<int, int>> blockedSet;
    for (auto& cell : blocked) {
        blockedSet.insert({cell[0], cell[1]});
    }
    
    auto bfs = [&](vector<int>& start, vector<int>& end) -> bool {
        if (start == end) return true;
        
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        
        q.push({start[0], start[1]});
        visited.insert({start[0], start[1]});
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            if (visited.size() > maxEnclosed) return true;
            
            auto curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000) continue;
                
                pair<int, int> pos = {nx, ny};
                if (blockedSet.count(pos) || visited.count(pos)) continue;
                
                if (nx == end[0] && ny == end[1]) return true;
                
                visited.insert(pos);
                q.push(pos);
            }
        }
        return false;
    };
    
    return bfs(source, target) && bfs(target, source);
}
};