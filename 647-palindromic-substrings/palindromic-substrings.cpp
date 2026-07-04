class Solution {
private:
    bool isPalin(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                if(isPalin(i,j,s)){
                    result++;
                }
            }
        }
        return result;
    }
};