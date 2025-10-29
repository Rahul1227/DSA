class Solution {
public:
    int smallestNumber(int n) {
        vector<int> vec = {1,3,7,15,31,63,127,255,511,1023} ;
        for(auto it: vec){
            if(it >= n) return it ;
        }
        return 0 ;
    }
};