class Solution {
private:
    int getArea(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int currInd = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int width = nse - pse -1;
                int height = arr[currInd];
                int currArea = width * height;
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int currInd = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse -1;
            int height = arr[currInd];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);

        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        vector<int> currArr(col, 0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '1'){
                    currArr[j] = currArr[j]+1;
                }else{
                    currArr[j] = 0;
                }
            }
            int currArea = getArea(currArr);
            maxArea = max(maxArea, currArea);
        }

        return maxArea;

        
    }
};