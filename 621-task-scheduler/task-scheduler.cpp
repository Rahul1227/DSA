class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        // max heap to  store the frequence of the tasks
        priority_queue<int> pq;

        for(auto &c : tasks){
            mp[c-'A']++;
        }

        for(int i =0; i<26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }
        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<= n+1; i++){
                if(!pq.empty()){
                    int topFrq = pq.top();
                    pq.pop();
                    topFrq--;
                    
                        temp.push_back(topFrq);
                   
                }
                
            }

            for(int i =0; i< temp.size(); i++){
                if(temp[i] > 0){
                    pq.push(temp[i]);
                }
                
            }

            if(!pq.empty()){
                time += n+1;
                
            }else{
                time += temp.size();

            }
        }

        return time;
        
    }
};