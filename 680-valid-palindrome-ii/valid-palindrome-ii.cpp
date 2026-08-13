class Solution {
private:
    bool solve(int i, int j, string &s){
        while( i< j){
            if(s[i] != s[j]) return false;
            i++;
            j--;

        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int k = 1;

        int i =0;
        int j = n-1;

        while(i < j){
            if(s[i] != s[j] && k){
                k = 0;
                return solve(i+1,j,s ) || solve(i, j-1, s); 
            }
            i++;
            j--;
        }

        return true;
        
    }
};