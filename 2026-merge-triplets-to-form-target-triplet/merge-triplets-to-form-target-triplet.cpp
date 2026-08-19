class Solution {
private:
    bool isValid(vector<int> &curr, vector<int> &target){
        for(int i=0; i<3; i++){
            if(curr[i] > target[i]) return false;
        }
        return true;
    }

    vector<int> merge(vector<int> curr, vector<int> next){
        for(int i=0; i<3; i++){
            curr[i] = max(curr[i], next[i]);
        }
        return curr;
    }
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = {0,0,0};
        for(int i=0; i<triplets.size(); i++){
            vector<int> merged = merge(curr, triplets[i]);
            if(isValid(merged, target)){
                curr = merged;
            }

        }

        for(int i=0; i<3; i++){
            if(curr[i] != target[i]){
                return false;
            }
        }
        return true;
        
    }
};