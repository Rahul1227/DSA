class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i =0;
        int j = 0;
        int k = 0;
        while(i<n && j < n){
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            chars[k++] = chars[i];
            int len = j - i;

            if(len > 1){
                string lenStr = to_string(len);
                for(char c : lenStr){
                    chars[k++] = c;
                }
            }
            
           
            i = j;
            
        }
        return k--;
        
    }
};