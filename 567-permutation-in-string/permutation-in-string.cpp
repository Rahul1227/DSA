class Solution {
private:
    bool isValid(vector<int> &needed){
        for(auto num  : needed){
            if(num != 0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        vector<int> needed(26, 0);
        int j;
        for(j =0; j<n1; j++){
            needed[s1[j] - 'a']++;
            needed[s2[j] - 'a']--;
        }
        if(isValid(needed)) return true;
        int i =0;
        while(j<n2){
            needed[s2[j] -'a']--;
            if(j-i+1 > n1){
                needed[s2[i]-'a']++;
                i++;
            }
            if(isValid(needed)) return true;
            j++;
        }

        return false;

        
    }
};