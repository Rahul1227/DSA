class Solution {
private:
    bool check(int i, int j, int ind, string& word, vector<vector<char>>& board,
               vector<vector<int>>& visited) {
        // base condition
        int m = board.size();
        int n = board[0].size();

        if (ind == word.size()) {
            return true;
        }

        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, 1, -1};

        for (int x = 0; x < 4; x++) {
            int newI = i + dirX[x];
            int newJ = j + dirY[x];

            // validity check
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n &&
                !visited[newI][newJ] && board[newI][newJ] == word[ind]) {
                visited[newI][newJ] = 1;
                if(check(newI, newJ, ind + 1, word, board, visited)) return true;
                visited[newI][newJ] = 0;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // finding the starting letter of the word and then starting the search
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    visited[i][j] = 1;
                    if (check(i, j, 1, word, board, visited))
                        return true;
                }
            }
        }

        return false;
    }
};