class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int ind = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(ind < n){
            return letters[ind];
        }else{
            return letters[0];
        }
        
        
    }
};