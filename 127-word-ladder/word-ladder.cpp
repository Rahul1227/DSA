class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        st.erase(beginWord);

        // starting of the loop
        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();
            for(int i =0; i<word.size(); i++){
                char iniLetter = word[i];

                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        if(word == endWord) return level+1;
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = iniLetter;
            }
        }

        return 0;
        
    }
};