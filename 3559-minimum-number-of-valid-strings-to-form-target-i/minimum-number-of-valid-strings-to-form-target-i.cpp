class Solution {
private:
    vector<int> getZArray(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i =1;
        while(i<n){
            if(s[i]  == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else if(len != 0){
                len = lps[len-1];
            }else{
                i++;
            }
        }

        return lps;







        // int l = 0;
        // int r = 0;
        // for (int i = 1; i < n; i++) {
        //     // i is out of range
        //     if (i > r) {
        //         l = i;
        //         r = i;
        //         while (r < n && s[r] == s[r - l]) {
        //             r++;
        //         }
        //         z[i] = r - l;
        //         r--;
        //     } else {
        //         // i is in the range
        //         int k = i - l;
        //         // if z[k] is in the range
        //         if (z[k] < r - i + 1) {
        //             z[i] = z[k];
        //         } else {
        //             l = i;
        //             while (r < n && s[r] == s[r - l]) {
        //                 r++;
        //             }
        //             z[i] = r - l;
        //             r--;
        //         }
        //     }
        // }

        // return z;
    }

public:
    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>> zArrays;
        for(auto word: words){
            string newWord = word + '$' + target;
            auto result = getZArray(newWord);
            vector<int> temp;
            int extra = word.size();
            for(int i=extra; i<result.size(); i++){
                temp.push_back(result[i]);
            }
            zArrays.push_back(temp);
        }

        // for(auto zArray : zArrays){
        //     for(auto num : zArray){
        //         cout<<num<<" ";
        //     }
        //     cout<<endl;
        // }
        int count =0;
        int len = target.size();
        while(len > 0){
            int currMax = 0;
            for(int i=0; i<zArrays.size(); i++){
                currMax = max(currMax, zArrays[i][len]);
            }
            if(currMax == 0) return -1;
            len -= currMax;
            count++;
        }

        return count;
    }
};