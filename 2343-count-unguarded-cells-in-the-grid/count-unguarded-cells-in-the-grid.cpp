class Solution {
private:
    void markingGuarded(int rol, int col, vector<vector<char>> &mat){
        // checking col
        int m = mat.size();
        int n = mat[0].size();
        //right
        for(int i = col +1; i<n; i++){
            if(mat[rol][i] != 'g' && mat[rol][i] !='w'){
                mat[rol][i] = 'v';
            }else{
                break;
            }
        }

        //left
        for(int i = col -1; i>=0; i--){
            if(mat[rol][i] != 'g' && mat[rol][i] !='w'){
                mat[rol][i] = 'v';
            }else{
                break;
            }
        }
        
        //down
        for(int i = rol + 1; i<m; i++){
            if(mat[i][col] != 'g' && mat[i][col] != 'w'){
                mat[i][col] = 'v';
            }else{
                break;
            }
        }

        //up

         for(int i = rol - 1; i>=0; i--){
            if(mat[i][col] != 'g' && mat[i][col] != 'w'){
                mat[i][col] = 'v';
            }else{
                break;
            }
        }

    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> mat(m, vector<char>(n,'u'));
        // placing the walls
        for(int i =0; i<walls.size(); i++){
            int rol = walls[i][0];
            int col = walls[i][1];
            mat[rol][col] = 'w';
        }

        // placing the guards
        for(int i =0; i<guards.size(); i++){
            int rol = guards[i][0];
            int col = guards[i][1];
            mat[rol][col] = 'g';
        }

        // marking the guard
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 'g'){
                    markingGuarded(i,j,mat);
                }
            }
        }

        // priting the mat
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;

        }



        int ans = 0;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 'u'){
                    ans++;
                }
            }

        }

        return ans;
        
    }
};