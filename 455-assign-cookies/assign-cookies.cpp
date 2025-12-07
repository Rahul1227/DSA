class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int len1 = g.size();
        int len2 = s.size();
        if(len2 == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans =0;
        int i =0;
        int j = 0;
        while(i < len1 && j < len2){
            if(s[j] >= g[i]){
                i++;
                j++;
                ans++;
            }else{
                j++;
            }
        }

        return ans;



        
    }
};