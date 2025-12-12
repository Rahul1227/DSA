class Solution {
private: 
    int largestRectangleArea(vector<int>& heights) {
        // trying to solve in 1 pass;
        int maxArea = INT_MIN;
        int n = heights.size();
        stack<int> st;
        st.push(0);

        for(int i =1 ; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int currHeight = heights[st.top()];
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                int nse = i;
                int currArea = (nse - pse - 1) * currHeight;
                maxArea = max(currArea, maxArea);
            }
            st.push(i);
        }

        while(!st.empty()){
                int currHeight = heights[st.top()];
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                int nse = n;
                int currArea = (nse - pse - 1) * currHeight;
                maxArea = max(currArea, maxArea);
        }
        return maxArea;
    }       
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> currHisto(m,0);
        int globalMaxArea = INT_MIN;
        for(int i =0; i<n; i++){
            //  forming the histogram
            for(int j =0; j<m; j++){
                if(matrix[i][j] == '0'){
                    currHisto[j] = 0;
                }else{
                    currHisto[j] += matrix[i][j] - '0';
                }

            }

            int currArea = largestRectangleArea(currHisto);
            globalMaxArea = max(globalMaxArea, currArea);
        }

        return globalMaxArea;
        
    }
};