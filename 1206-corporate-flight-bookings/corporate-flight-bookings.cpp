class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);
        for(auto booking : bookings){
            int start = booking[0];
            int end = booking[1];
            int seats = booking[2];
            diff[start] += seats;
            diff[end + 1] -= seats;
        }
        vector<int> ans;
        int currSeats = 0;
        for(int i=1; i<=n; i++){
            currSeats += diff[i];
            ans.push_back(currSeats);
        }
        return ans;
        
    }
};