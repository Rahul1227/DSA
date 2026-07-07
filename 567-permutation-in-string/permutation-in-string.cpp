class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        if (m > n) return false;

        unordered_map<char,int> need;
        for (char c : s1) need[c]++;
        int required = need.size();
        int matched = 0;

        unordered_map<char,int> window;
        int i = 0;
        for (int j = 0; j < n; j++) {
            char c = s2[j];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) matched++;
            }

            if (j - i + 1 > m) {
                char l = s2[i];
                if (need.count(l)) {
                    if (window[l] == need[l]) matched--;
                    window[l]--;
                }
                i++;
            }

            if (j - i + 1 == m && matched == required) return true;
        }
        return false;
    }
};