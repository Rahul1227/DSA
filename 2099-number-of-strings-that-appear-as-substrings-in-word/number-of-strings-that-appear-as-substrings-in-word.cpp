class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto pattern : patterns){
            int i = 0;
            int j = 0;
            while(i < pattern.size() && j < word.size()){
                if(pattern[i] == word[j]){
                    i++;
                    j++;
                }else{
                    j = j - i + 1;
                    i = 0;
                }
            }

            if(i == pattern.size()){
                count++;
            }
        }

        return count;
    }
};