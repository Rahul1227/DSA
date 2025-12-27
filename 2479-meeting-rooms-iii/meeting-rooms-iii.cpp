class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            allocatedRooms;

        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        sort(meetings.begin(), meetings.end());

        for(int i =0; i<meetings.size(); i++){
            int startTime = meetings[i][0];
            int endTime = meetings[i][1];

            while(!allocatedRooms.empty() && allocatedRooms.top().first <= startTime){
                auto [time, room] = allocatedRooms.top();
                allocatedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                count[room]++;
                allocatedRooms.push({endTime, room});
            }else{
                int duration = endTime - startTime;
                auto [endingOn, room] = allocatedRooms.top();
                allocatedRooms.pop();
                count[room]++;
                allocatedRooms.push({endingOn + duration, room});
            }
        }

        int ans = INT_MIN;
        int ind = -1;
        for(int i =0; i<n; i++){
            if(count[i] > ans){
                ans = count[i];
                ind =  i;
            }
        }
        return ind;
        
    }
};