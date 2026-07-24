class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto c : tasks){
            freq[c-'A']++;
        }

        priority_queue<int> pq;
        for(auto num : freq){
            if(num > 0){
                pq.push(num);
            }
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i =0; i<=n; i++){
                if(!pq.empty()){
                    int currFreq = pq.top();
                    pq.pop();
                    temp.push_back(--currFreq);
                }
            }

            for(auto f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }

        return time;


        
    }
};