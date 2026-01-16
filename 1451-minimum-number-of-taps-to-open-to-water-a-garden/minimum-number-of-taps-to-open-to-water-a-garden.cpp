class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }

    int minTaps(int n, vector<int>& ranges) {

        vector<pair<int,int>> range;

        // building intervals
        for (int i = 0; i <= n; i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            range.push_back({l, r});
        }

        sort(range.begin(), range.end(), cmp);

        int taps = 0;
        int i = 0;
        int maxReach = 0;

        while (maxReach < n) {

            int best = maxReach;

            while (i < range.size() && range[i].first <= maxReach) {
                best = max(best, range[i].second);
                i++;
            }

            // cannot extend coverage
            if (best == maxReach) return -1;

            taps++;
            maxReach = best;
        }

        return taps;
    }
};
