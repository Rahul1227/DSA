class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        int minDiff = INT_MAX;
        for(int i =1; i<n; i++){
            int currDiff = arr[i] - arr[i-1];
            minDiff = min(currDiff, minDiff);
        }

        for(int i =1; i<n; i++){
            int currDiff = arr[i] - arr[i-1];
            if(currDiff == minDiff){
                // cout<<"reached inside the conditon";
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
        
    }
};