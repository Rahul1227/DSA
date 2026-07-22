class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        int i =0;
        while(i < boxTypes.size() && truckSize){
            int allowed = min(truckSize, boxTypes[i][0]);
            truckSize -= allowed;
            ans += allowed * boxTypes[i][1];
            i++;
        }
        return ans;
        
    }
};