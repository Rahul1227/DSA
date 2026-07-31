class Solution {
private:
    vector<int> getNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for(int i =0; i< n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> getPSE(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return pse;

    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = getNSE(heights);
        vector<int> pse = getPSE(heights);
        int maxArea = 0;

        for(int i =0; i< heights.size(); i++){
            int weight = nse[i] - pse[i] -1;
            int currArea = weight * heights[i];
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
        
    }
};