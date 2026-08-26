class Solution {
string getSmaller(string s1, string s2){
    return "";
}
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len = INT_MAX;
        string ans ="";
        int n = s.size();
        int i=0; 
        int j =0;
        int count = 0;

        while(j<n){
            if(s[j] == '1'){
                count++;
            }

            while(count > k){
                if(s[i] =='1'){
                    count--;
                }
                i++;
            }

            while(s[i] == '0'){
                i++;
            }

            if(count == k){
                int currLen = j-i+1;
                string currStr = s.substr(i, currLen);
                if(currLen < len){
                    len = currLen;
                    ans = currStr;
                }else if(currLen == len){
                    if(ans > currStr){
                        ans = currStr;
                    }
                }
            }
            j++;

        }

        return ans;

        
    }
};