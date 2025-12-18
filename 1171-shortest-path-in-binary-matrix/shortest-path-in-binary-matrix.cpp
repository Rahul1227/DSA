class Solution {
private:
    bool isValid(int i, int j, vector<vector<int>>& grid,
                 vector<vector<int>>& visited) {
        int n = grid.size();
        if (i >= 0 && i < n && j >= 0 && j < n && !visited[i][j] &&
            grid[i][j] == 0)
            return true;
        return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>> pq; // we need max-heap here
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int, int>> dir;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                dir.push_back({i, j});
            }
        }
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        pq.push({0, 0});
        visited[0][0] = 1;
        while (!pq.empty()) {
            int currLen = pq.size();
            for (int time = 0; time < currLen; time++) {

                auto [x, y] = pq.front();
                pq.pop();
                if (x == n - 1 && y == n - 1)
                    return count + 1;

                for (int i = 0; i < dir.size(); i++) {
                    int newX = x + dir[i].first;
                    int newY = y + dir[i].second;

                    if (isValid(newX, newY, grid, visited)) {
                        pq.push({newX, newY});
                        visited[newX][newY] = 1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};