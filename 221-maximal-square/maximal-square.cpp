class Solution {
private:
    int getCurrArea(vector<int> &arr){
        arr.push_back(0);
        int n = arr.size();
        stack<int> st;
        st.push(0);
        int maxArea = 0;

        for(int i =1; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int currHeight = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = !st.empty() ? st.top() : -1;
                int minSide = min((nse - pse -1), currHeight);
                int currArea = minSide * minSide;
                maxArea = max(maxArea,currArea);
            }
            st.push(i);
        }

        return maxArea;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m  = matrix[0].size();
        vector<int> currMat(m, 0);
        int globalMax = 0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m;  j++){
                if(matrix[i][j] != '0'){
                    currMat[j] += matrix[i][j] - '0';

                }else{
                    currMat[j] = 0;
                }
            }

            int currArea = getCurrArea(currMat);
            globalMax = max(globalMax, currArea);
        }

        return globalMax;
        
    }
};