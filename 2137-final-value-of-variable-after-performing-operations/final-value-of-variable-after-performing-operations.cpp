class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(auto ops: operations){
            if(ops == "++X" || ops == "X++"){
                val++;
            }else{
                val--;
            }
        }
        return val;
        

    }
};