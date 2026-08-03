class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        priority_queue<pair<int,int>> pq;
        for(int i =0; i< aliceValues.size(); i++){
            pq.push({aliceValues[i] + bobValues[i], i});
        }

        int Alice = 1;
        int AliceScore = 0;
        int BobScore = 0;
        while(!pq.empty()){
            auto [val,  ind] = pq.top();
            pq.pop();
            if(Alice){
                AliceScore += aliceValues[ind];
            }else{
                BobScore += bobValues[ind];
            }
            Alice = 1 - Alice;
        }

        if(AliceScore > BobScore) return 1;
        else if(BobScore > AliceScore) return -1;
        return 0;


    }
};