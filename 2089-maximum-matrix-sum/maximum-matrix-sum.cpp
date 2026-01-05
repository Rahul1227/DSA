class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int oddCount = 0;
        int minElement = INT_MAX;
        int n = matrix.size();

        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                int element = matrix[i][j];
                sum += abs(element);
                minElement = min(minElement, abs(element));
                if(element < 0){
                    oddCount++;
                }

               
            }
        }

        if(oddCount % 2 == 0){
            return sum;
        }else{
            cout<<"sum: "<<sum;
            cout<<minElement;
            return sum - 2 * minElement;
        }
        
    }
};