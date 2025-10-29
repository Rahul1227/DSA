class Solution {
public:
    int smallestNumber(int n) {
        int counter = 0;
        while(n > 0){
            n = n >> 1;
            counter++;


        }
        cout<<counter;

        return pow(2,counter)- 1;


        
        
    }
};