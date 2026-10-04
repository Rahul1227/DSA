class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(auto &str: wordList){
            dict.insert(str);
        }

        if(!dict.count(endWord)) return 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);

        int count = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto u = q.front();
                q.pop();
                if(u == endWord) return count;

                for(int i=0; i<u.size(); i++){
                    for(int j=0; j<26; j++){
                        int currChar = u[i] -'a';
                        if(j == currChar) continue;

                        string newWord = u;
                        newWord[i] = j +'a';
                        if(!dict.count(newWord)) continue;
                        if(!visited.count(newWord)){
                            q.push(newWord);
                            visited.insert(newWord);
                        }
                    }
                }

            }
            count++;
        }

        return 0;
        
    }
};