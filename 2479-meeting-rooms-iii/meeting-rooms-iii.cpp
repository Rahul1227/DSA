class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> usedCount(n,0);

        priority_queue<int, vector<int>, greater<int>> avaliableRooms;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> usedRooms;

        sort(meetings.begin(), meetings.end());

        // initially all rooms are free
        for(int i = 0; i < n; i++){
            avaliableRooms.push(i);
        }

        for(int i = 0; i < meetings.size(); i++){
            long long currStart = meetings[i][0];
            long long currEnd = meetings[i][1];

            // free rooms that have finished before currStart
            while(!usedRooms.empty() && usedRooms.top().first <= currStart){
                auto p = usedRooms.top();
                usedRooms.pop();
                avaliableRooms.push(p.second);
            }

            if(!avaliableRooms.empty()){
                int room = avaliableRooms.top();
                avaliableRooms.pop();
                usedRooms.push({currEnd, room});
                usedCount[room]++;
            } else {
                auto p = usedRooms.top();
                usedRooms.pop();
                long long endT = p.first;
                int room = p.second;

                long long duration = currEnd - currStart;
                long long newEnd = endT + duration;

                usedRooms.push({newEnd, room});
                usedCount[room]++;
            }
        }

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(usedCount[i] > usedCount[ans]){
                ans = i;
            }
        }

        return ans;
    }
};
