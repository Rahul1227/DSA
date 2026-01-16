class Solution {
private:
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }

        return a.first < b.first;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> interval;
        for(int i =0; i<=n; i++){
            int start = max(0, i-ranges[i]);
            int end = min(n, i + ranges[i]);
            interval.push_back({start, end});
        }

        if(interval.size() == 0) return -1;
        sort(interval.begin(), interval.end());

        int taps =  0;
        int currEnd = 0;
        int i =0;
        while(currEnd < n){
            if(i >= interval.size()) return -1;

            if(interval[i].first > currEnd +1) return -1;

            int maxReach = currEnd;
            while(i<interval.size() && interval[i].first <= currEnd){
                maxReach = max(maxReach, interval[i].second);
                i++;
            }

            if(maxReach == currEnd) return -1;

            currEnd = maxReach;
            taps++;
        }

        return taps;

        
    }
};