class Solution {
private:
    bool isInt(double x){
        return floor(x) == x;
    }
public:
    int countTriples(int n) {
        int count = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1;j<=n; j++){
                int sumOfSq = i * i + j * j;
                double sqroot = 1.0 * sqrt(sumOfSq);
                if( isInt(sqroot) && sqroot<=n ) count++;
            }
        }

        return count;
        
    }
};