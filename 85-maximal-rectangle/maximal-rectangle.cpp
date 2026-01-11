class Solution {
private:
    int largestRectangleArea(vector<int>& height) {
        // if no pse, pse = -1 (out of range)
        // if no nse, nse = n (out of range)
        int n = height.size();
        int maxArea = INT_MIN;
        stack<int> st;
        for(int i =0; i<n; i++){
            while(!st.empty() && height[i] < height[st.top()]){
                int currHeight = height[st.top()];
                st.pop();
                // for nse and pse, we are considering the indices
                // indices are pushed into the stack
                int nse = i;
                int pse = (!st.empty() ? st.top() : -1);
                int currArea = (nse - pse - 1) * currHeight;
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int currHeight = height[st.top()];
            st.pop();
            int nse = n;
            int pse = (!st.empty()? st.top():-1);
            int currArea = (nse-pse-1) * currHeight;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col,0);
        int maxArea = INT_MIN;
        for(int i =0; i<row; i++){
            for(int j =0; j<col; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += matrix[i][j] - '0';
                }else{
                    heights[j] = 0;
                }
            }

            int currArea = largestRectangleArea(heights);
            maxArea = max(currArea, maxArea);
        }

        return maxArea;


        

    }
};