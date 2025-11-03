class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // more optimized solution

        int result = 0;
        for(int i =1; i< colors.size(); i++){
            if(colors[i] == colors[i-1]){
                result += min(neededTime[i], neededTime[i-1]);
                neededTime[i] = max(neededTime[i], neededTime[i-1]);
            }
        }

        return result;



        // int n = colors.size();
        // int i =0;
        // int j =1;
        // int result = 0;
        // while(j<n){
        //     while(j<n && colors[i] == colors[j]){
        //         j++;
        //     }
        //     if(j-i > 1){
        //         vector<int> temp;
        //         for(int k =i; k<j; k++){
        //             temp.push_back(neededTime[k]);

        //         }
        //         // sort(temp.begin(), temp.end());
        //         int sum = accumulate(temp.begin(), temp.end(),0);
        //         int maxVal = *max_element(temp.begin(), temp.end());
        //         sum -= maxVal;
        //         result += sum;
                
        //     }
        //     i =j;
        //     j++;
        // }
        // return result;
        
    }
};