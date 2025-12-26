class Solution {
private:    
    int calculatePenalty(int ind, string & customers){
        int currPenalty = 0;
        for(int i=0; i<ind; i++){
            if(customers[i] == 'N'){
                currPenalty++;
            }
        }

        for(int i=ind; i<customers.size(); i++){
            if(customers[i] =='Y'){
                currPenalty++;
            }
        }

        return currPenalty;
    }
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();
        int currPenalty =0;
        for(int i=0; i<n; i++){
            if(customers[i]== 'Y'){
                currPenalty++;

            }
        }
        int minPenalty = currPenalty;
        int ansInd = 0;

        // lets do the maths
        for(int i = 1; i<=n; i++){
            if(customers[i-1] == 'Y'){
                currPenalty--;
            }else{
                currPenalty++;
            }
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                ansInd = i;
            }
        }

        return ansInd;

        
    }
};