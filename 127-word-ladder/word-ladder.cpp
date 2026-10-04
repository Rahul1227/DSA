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
                    int currChar = u[i] -'a';
                    for(char c ='a'; c<='z'; c++){
                       
                        if(c == currChar) continue;

                        u[i] = c;
                        if(!dict.count(u)) continue;
                        if(!visited.count(u)){
                            q.push(u);
                            visited.insert(u);
                        }
                    }
                    u[i] = currChar +'a';
                }

            }
            count++;
        }

        return 0;
        
    }
};