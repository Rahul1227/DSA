class MyCalendarThree {
public:
    map<int,int> events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime]++;
        events[endTime]--;
        int currBooking = 0;
        int maxBooking = 0;
        for(auto [key, val] : events){
            currBooking += val;
            maxBooking = max(maxBooking, currBooking);
        }
        return maxBooking;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */