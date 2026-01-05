class Solution {
private:
    bool isValid(int row, int col, char digit, vector<vector<char>> &board){
        // checking row and the col
        for(int i = 0; i<9; i++){
            // col check
            if(board[row][i] == digit) return false;
            // row check
            if(board[i][col] == digit) return false;
        }

        int start_i = (row/ 3) * 3;
        int start_j = (col/3) * 3;

        for(int i = 0; i<3; i++){
            for(int j =0; j<3; j++){
                if(board[start_i + i][start_j + j] == digit) return false;
            }
        } 
        return true;
    }




    bool solve(vector<vector<char>> &board){
        for(int i =0; i<9; i++){
            for(int j =0; j<9; j++){
                if(board[i][j] == '.'){
                    for(char digit = '1'; digit<= '9'; digit++){
                        if(isValid(i,j,digit,board)){
                            board[i][j] = digit;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};