class Solution {
private:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &board){
        int n = board.size();
        int m = board[0].size();
        visited[i][j] =1;

        static int dirX[] = {-1,1,0,0};
        static int dirY[] = {0,0,1,-1};

        for(int ind=0; ind<4; ind++){
            int newI = i+dirX[ind];
            int newJ = j+ dirY[ind];

            if(newI >=0 && newI < n && newJ >=0 && newJ <m && !visited[newI][newJ] && board[newI][newJ] == 'O'){
                dfs(newI, newJ,visited,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        

        // visiting the rows
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0,j,visited,board);
            }

            if(board[n-1][j] =='O' && !visited[n-1][j]){
                dfs(n-1,j,visited,board);
            }
        }

        //visiting the columns

        for(int i=0; i<n; i++){
            if(board[i][0] =='O' && !visited[i][0]){
                dfs(i,0,visited,board);
            }

            if(board[i][m-1] == 'O'&& !visited[i][m-1]){
                dfs(i,m-1,visited,board);
            }
        }


        for(int i=0;  i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};