class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for(auto &str: deadends){
            st.insert(str);
        }
        if(st.count("0000")) return -1;
        queue<string> q;
        q.push("0000");

        int steps = 0;
        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                string u = q.front();
                q.pop();
                if(u == target) return steps;

                for(int z=0; z<4; z++){
                    string currStr = u;
                    int currChar = currStr[z] -'0';
                    int nextMove = (currChar + 1) % 10;
                    currStr[z] = nextMove + '0';

                    if(!st.count(currStr) && !visited.count(currStr)){
                        q.push(currStr);
                        visited.insert(currStr);

                    }

                    int prevMove = (currChar -1 + 10) %10;
                    string newStr = u;
                    newStr[z] =prevMove + '0';

                    if(!st.count(newStr) && !visited.count(newStr)){
                        q.push(newStr);
                        visited.insert(newStr);
                    }

                    

                }
            }
            steps++;
        }

        return -1;
        
    }
};