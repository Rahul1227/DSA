class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        vector<int> freq(26, 0);
        for(auto c: tasks){
            freq[c-'A']++;
        }
        priority_queue<int> pq;
        for(auto num: freq){
            if(num > 0){
                pq.push(num);
            }
            
        }

        int ans = 0;
        while(!pq.empty()){
            vector<int> temp;
            int count = 0;
            while(!pq.empty() && count < n){
                int topEle = pq.top();
                temp.push_back(topEle-1);
                pq.pop();
                count++;
            }

            int tempSize = temp.size();

            bool pushed = false;

            for(int i=0; i<tempSize; i++){
                int newVal = temp[i];
                if(newVal > 0){
                    pq.push(newVal);
                    pushed = true;
                }

            }

            if(pushed){
                ans += n;
            }else{
                ans += tempSize;
              
            }
            

        }

        return ans;




    }
};