class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int i =0; i<1024; i++){
            int hour = i >> 6;
            int mins = i & 63; // 63 = 11111
            if(hour < 12 && mins < 60 && __builtin_popcount(i) == turnedOn){
                string ans = to_string(hour);
                ans += ":";
                if(mins < 10){
                    ans += '0';
                }
                ans += to_string(mins);
                result.push_back(ans);
                
            }

        }

        return result;
    }
};