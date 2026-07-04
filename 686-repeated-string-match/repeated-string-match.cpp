class Solution {
private:
    int getCount(int i, string &a, string &b){
        int count = 1;
        int j = 0;
        int n1= a.size();
        int n2 = b.size();

        while( j < n2){
            if(a[i] == b[j]){
                i++;
                j++;
                if(j < n2 && i == n1){
                    count++;
                    i = 0;
                }
            }else{
                return -1;
            }
        }
        return count;
    }
public:
    int repeatedStringMatch(string a, string b) {
        for(int i =0; i<a.size(); i++){
            if(a[i] == b[0]){
                int count = getCount(i, a, b);
                if(count != -1) return count;
            }
        }

        return -1;
        
    }
};