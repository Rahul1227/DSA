class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        // check rows
        for (int row = 0; row < n; row++) {
            vector<int> hashMap(9, 0);
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') continue;
                int num = board[row][col] - '1';
                if (hashMap[num] > 0) return false;
                hashMap[num]++;
            }
        }

        // check cols
        for (int col = 0; col < n; col++) {
            vector<int> hashMap(9, 0);
            for (int row = 0; row < n; row++) {
                if (board[row][col] == '.') continue;
                int num = board[row][col] - '1';
                if (hashMap[num] > 0) return false;
                hashMap[num]++;
            }
        }

        // check 3x3 sub-boxes
        for (int blockRow = 0; blockRow < 9; blockRow += 3) {
            for (int blockCol = 0; blockCol < 9; blockCol += 3) {
                vector<int> hashMap(9, 0);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = blockRow + i;
                        int col = blockCol + j;
                        if (board[row][col] == '.') continue;
                        int num = board[row][col] - '1';
                        if (hashMap[num] > 0) return false;
                        hashMap[num]++;
                    }
                }
            }
        }

        return true; // valid sudoku
    }
};
