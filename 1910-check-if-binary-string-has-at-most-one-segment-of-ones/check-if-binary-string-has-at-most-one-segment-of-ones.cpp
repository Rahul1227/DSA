class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i =0;
        // bool found = false;
        while(i < n && s[i] != '0'){
            i++;
        }

        // if(i== n) return false;

        while(i<n){
            if(s[i] == '1') return false;
            i++;

        }

        return true;

        
    }
};