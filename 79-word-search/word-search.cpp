class Solution {
private:
    bool solve(int i, int j, vector<vector<int>> &visited, int ind,
     vector<vector<char>> &board, string &word){
        // if(board[i][j] != word[ind]) return false;
        int m = board.size();
        int n = board[0].size();
        
        if(ind == word.size()){
            return true;
        }
        // visited[i][j] = 1;
        int dirX[] ={-1,1,0,0};
        int dirY[] ={0,0,1,-1};

        for(int z =0; z<4; z++){
            int newI = i + dirX[z];
            int newJ = j + dirY[z];

            if(newI>=0 && newI <m && newJ >=0 && newJ < n && 
            !visited[newI][newJ] && board[newI][newJ] == word[ind]){
                visited[newI][newJ] = 1;
                if(solve(newI, newJ, visited, ind+1, board, word)) return true;
                visited[newI][newJ] = 0;
            }
        }
        return false;



     }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(solve(i,j,visited,1,board, word)) return true;
                    visited[i][j] = 0;
                }
               
            }

        }
        return false;
    }
};