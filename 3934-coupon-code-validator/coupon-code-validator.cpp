class Solution {
private:
    bool isValidBusiness(string str){
        static unordered_set<string> st ={"electronics", "grocery","pharmacy","restaurant"};
        if(st.find(str) != st.end()) return true;
        return false;
    }


    bool isCodeValid(string str){
        if(!str.size()) return false;
        for(char c: str){
            if((c >= 'a' && c<='z') ||(c >= 'A' && c<='Z') || 
                    (c >= '0' && c<='9') || c =='_') continue;
            else return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> ans;

        int n = code.size();
        for(int i =0; i<n; i++){
            string currCode = code[i];
            string currBusinessLine = businessLine[i];
            bool currIsActive = isActive[i];

            if( isValidBusiness(currBusinessLine) && isCodeValid(currCode) && currIsActive){
                ans.push_back({currBusinessLine, currCode});
            }
        }

        sort(ans.begin(), ans.end());
        vector<string> finalAns;
        for(int i =0;  i< ans.size(); i++){
            finalAns.push_back(ans[i].second);

        }

        
        return finalAns;


        
    }
};