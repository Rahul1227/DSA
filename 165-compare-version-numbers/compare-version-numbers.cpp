class Solution {
private:   
    vector<int> getIntergerFromToken(string &version){
        vector<int> ans;
        stringstream v1Token(version);
        string num;

        while(getline(v1Token, num, '.')){
            ans.push_back(stoi(num));
        }

        return ans;

    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getIntergerFromToken(version1);
        vector<int> v2 = getIntergerFromToken(version2);

        int len =  max((int)v1.size(), (int)v2.size());

        for(int i =0;  i<len; i++){
            int num1 = (i<v1.size()) ? v1[i]: 0;
            int num2 = (i<v2.size()) ? v2[i]:0;
            if(num1 <num2) return -1;
            if(num1 > num2) return 1;
        }

        
        return 0;
        
    }
};