class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>> mp;
        int n = grid.size();

        // populating the map
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                int ind = i-j;
                mp[ind].push_back(grid[i][j]);
            }
        }

        for(auto&[key, val] : mp){
            if(key >= 0){
                sort(val.begin(), val.end());
            }else{
                sort(val.begin(), val.end(), greater<int>());
            }
        }

        // printing for the sake of knowledge
        for(auto& [key, val]:mp){
            cout<<key<<"->";
            for(auto num : val){
                cout<<num<<" ";
            }
            cout<<endl;
        }

        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }


        return grid;
        
    }
};