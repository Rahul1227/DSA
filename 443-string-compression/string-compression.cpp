class Solution {
public:
    int compress(vector<char>& chars) {
        int ans =0;;
        int i =0;
        int j =0;
        int n = chars.size();
        while(j<n){
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            int len = j-i;
            chars[ans++] = chars[i];
            if(len > 1){
                string lenDigit = to_string(len);
                for(char c : lenDigit){
                    chars[ans++] = c;
                }
            }

            i=j;

        }
        return ans;
        
    }
};