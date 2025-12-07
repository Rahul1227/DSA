class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int len1 = players.size();
        int len2 = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int count =0;
        int i =0;
        int j =0;
        while(i<len1 && j < len2){
            if(players[i] <= trainers[j]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return count;
        
    }
};