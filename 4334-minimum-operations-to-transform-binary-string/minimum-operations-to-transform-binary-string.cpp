class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int i =0;
        int j =0;
        int cost =0;
        while(i < n && j<n){
            // direct conversion
            if(s1[i] == '0' && s2[j] == '1'){
                cost++;
                s1[i] = s2[j];
                // dependent of the neighbout to be 1
            }else if(s1[i] == '1' && s2[j] == '0'){
                if(i+1 < n){
                    if(s1[i+1] == '1'){
                        cost++;
                    }else{
                        cost +=2;
                    }
                    s1[i+1] = s2[j];
                }else if(i-1 >= 0){
                    cost += 2;
                }else{
                    return -1;
                }
            }
            i++;
            j++;
        }

        return cost;
        
    }
};