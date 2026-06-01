class Solution {
private:
    bool solve(int i, int j, vector<vector<int>> &visited, int ind,
     vector<vector<char>> &board, string &word){
        
        if(ind == word.size()) return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if(visited[i][j] || board[i][j] != word[ind]) return false;
        
        visited[i][j] = 1;
        
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, 1, -1};

        for(int z = 0; z < 4; z++){
            if(solve(i + dirX[z], j + dirY[z], visited, ind+1, board, word))
                return true;
        }
        
        visited[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(solve(i, j, visited, 0, board, word)) return true;
        
        return false;
    }
};