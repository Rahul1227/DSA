class Solution {
    unordered_set<int> colCheck;
    unordered_set<int> rightDia;
    unordered_set<int> leftDia;

private:
    bool isValid(int row, int col, vector<string>& board) {
        // checking in the upper rows;
        int n = board.size();
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // checking in the rightDiagonal;
        int i = row - 1;
        int j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        // checking the leftDiagonal
        int x = row - 1;
        int y = col - 1;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans) {
        int n = board.size();
        if (row >= n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!colCheck.count(col) && !rightDia.count(row + col) &&
                !leftDia.count(row - col)) {
                colCheck.insert(col);
                rightDia.insert(row+col);
                leftDia.insert(row-col);
                board[row][col] = 'Q';
                solve(row + 1, board, ans);
                board[row][col] = '.';
                colCheck.erase(col);
                rightDia.erase(row+col);
                leftDia.erase(row-col);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, curr, ans);
        return ans;
    }
};