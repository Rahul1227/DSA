class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans ="";
        int n = num.size();
        if(n == k){
            return "0";
        }

        for(int i=0; i<n; i++){
            while(!ans.empty() && k && num[i] < ans.back()){
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        while(k--){
            ans.pop_back();
        }
        int i;
        for(i=0; i<ans.size(); i++){
            if(ans[i] !='0'){
                break;
            }
        }

        if(i == ans.size()){
            return "0";
        }

        return ans.substr(i);
        
    }
};