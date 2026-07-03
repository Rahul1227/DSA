class Solution {
private:
    // int getBeauty(int i, int j, string &s){
    //     vector<int> hashMap(26, 0);
    //     for(int z =i; z<=j; z++){
    //         hashMap[s[z] - 'a']
    //     }
    // }
public:
    int beautySum(string s) {
        int result =0;
        int n = s.size();
        for(int i =0; i<n; i++){
            unordered_map<int,int> hashMap;
            for(int j =i; j<n; j++){
                hashMap[s[j] -'a']++;
                if(j-i > 1){
                    int maxElement = 0;
                    int minElement = INT_MAX;
                    for(auto [key, val]: hashMap){
                        maxElement = max(maxElement, val);
                        minElement = min(minElement, val);
                    }
                    result += maxElement - minElement;
                }

            }
        }
        return result;
        
    }
};