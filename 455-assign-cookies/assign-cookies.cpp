class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(), g.end());
       sort(s.begin(), s.end());
       int satisfied = 0;

       int len1 = g.size();
       int len2 = s.size();
       int i =0;
       int j =0;
      
      while(i< len1 && j<len2){
        if(g[i] <= s[j]){
            satisfied++;
            i++;
            j++;
        }else{
            j++;
        }
      }
      return satisfied;
    }
        

};