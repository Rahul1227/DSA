class Solution {
public:
    static bool compare(int& a, int& b) {
        string x = to_string(a), y = to_string(b);
        return x + y > y + x;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        for (auto num : nums) {
            ans += to_string(num);
        }

        int i;
        for(i =0; i<ans.size(); i++){
            if(ans[i] != '0') break;
        }

        if( i == ans.size()){
            return "0";
        }else{
            return ans.substr(i);
        }
    }
};