class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.count(beginWord)){
            st.erase(beginWord);
        }

        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();
            if(word == endWord) return level;

            for(int i =0; i< word.size(); i++){
                char originalChar = word[i];

                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.count(word)){
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
        
    }
};