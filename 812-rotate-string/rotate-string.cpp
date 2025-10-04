class Solution {
public:
    bool rotateString(string s, string goal) {
       // cancatenating the string with itself will contain all the combination possible.

        int len1 = s.size();
        int len2 = goal.size();
        if(len1 != len2) return false;
        if(len1 == 0) return true;
        s = s + s;
        
        return s.find(goal) != string:: npos;
        
    }
};