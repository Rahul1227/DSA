class Solution {
public:
    int passThePillow(int n, int time) {
        int answer = 0;
        int numberOfPass = n-1;
        int order = time/ numberOfPass;
        int ind = time % numberOfPass;

        if(order %2 == 1){
            answer = n- ind;
        }else{
            answer = 1 + ind;
        }

        return answer;
        
    }
};