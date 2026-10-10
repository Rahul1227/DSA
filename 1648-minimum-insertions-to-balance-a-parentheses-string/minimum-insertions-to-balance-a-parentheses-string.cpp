class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                need += 2;

                // We need an even number of closing brackets.
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
            } else {
                need--;

                // No opening bracket was available.
                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};