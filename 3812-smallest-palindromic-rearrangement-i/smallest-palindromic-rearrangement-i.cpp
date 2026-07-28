class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(auto c : s){
            freq[c-'a']++;
        }

        string ans ="";
        int single = -1;
        for(int i =0; i<26; i++){
            if(freq[i] %2 != 0){
                single = i;
            }
            int times = freq[i]/2;
            for(int j=0; j<times; j++){
                ans += i +'a';
            }
        }

        string firstHalf = ans;
        reverse(ans.begin(), ans.end());
        if(single == -1){
            return firstHalf + ans;
        }else{
            firstHalf += single + 'a';
            return firstHalf + ans;
        }
        
        
    }
};