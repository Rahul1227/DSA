class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Option 1: keep the prefix equal to target
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Cannot match target[i].
            // Try to become greater at this position.
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    // Fill the remaining suffix as small as possible.
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Can't become greater here.
            // We must backtrack to an earlier position.
            break;
        }

        /*
            Either:
            1. We constructed target exactly, or
            2. We got stuck somewhere.

            In both cases, try changing an earlier position.
        */

        for (int i = ans.size() - 1; i >= 0; i--) {

            // Restore the character currently at position i.
            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            // Try the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = ans.substr(0, i);

                    result += char('a' + c);
                    freq[c]--;

                    // Remaining characters must be as small as possible.
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};