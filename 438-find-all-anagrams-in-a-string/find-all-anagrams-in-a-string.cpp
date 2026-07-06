class Solution {
private:
    bool isValid(vector<int> &needed){
        for(auto num : needed){
            if(num != 0) return false;
        }
        return true;

    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(m > n) return ans;
        vector<int> needed(26,0);
        // vector<int> present(26,0);

        for(int k =0; k<m; k++){
            needed[p[k]-'a']++;
            needed[s[k] - 'a']--;
        }

        int i =0;
        int j = m;
        if(isValid(needed)){
                ans.push_back(i);
            }
        while(j<n){
            needed[s[j] - 'a']--;
            if(j -i + 1 > m){
                needed[s[i] -'a']++;
                i++;
            }

            if(isValid(needed)){
                ans.push_back(i);
            }


            j++;


        }
        return ans;
        
    }
};