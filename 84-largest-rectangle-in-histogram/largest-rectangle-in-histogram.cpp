class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &heights){
        int n = heights.size();
        vector<int> nse(n,n);

        stack<int> st;
        st.push(0);

        for(int i =1; i<n; i++){
            
            while(!st.empty() && heights[i] < heights[st.top()]){
                nse[st.top()] = i;
                st.pop();
                
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> prevSmallerElement(vector<int> &heights){
        int n = heights.size();
        vector<int> pse(n, -1);

        stack<int> st;
        st.push(n-1);

        for(int i = n-2;  i>=0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return pse;
    }
public:
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

















        // vector<int> nse = nextSmallerElement(heights);
        // vector<int> pse = prevSmallerElement(heights);
        // // for(auto it: nse){
        // //     cout<<it<<" ";
        // // }

        // // for(auto it: pse){
        // //     cout<<it<<" ";
        // // }

        // int maxArea = INT_MIN;

        // for(int i =0; i< heights.size(); i++){
        //     int currArea = (nse[i] - pse[i] - 1) * heights[i];
        //     maxArea = max(currArea, maxArea);
        // }


        // return maxArea;
        
    }
};