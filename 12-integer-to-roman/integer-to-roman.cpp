class Solution {
public:
    string intToRoman(int num) {
        // Use vectors to maintain order (from largest to smallest)
        vector<pair<int, string>> values = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string ans = "";
        
        for (auto [val, symbol] : values) {
            if (num >= val) {
                int count = num / val;
                for (int i = 0; i < count; i++) {
                    ans += symbol;
                }
                num %= val;
            }
        }
        
        return ans;
    }
};