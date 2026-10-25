class BusBooking {
private:

    vector<vector<int>> bus;
    vector<vector<int>> cost;
    int totalTime = 0;
    int minTime = 0;

public:
    BusBooking(int n) {
        bus.assign(n+1, vector<int>(4, 0));
        cost.assign(n+1, vector<int>(4, 0));
        
        
    }
    
    void toggle(string seat) {
        char col = seat[0];
        int colNum = col -'A';
        seat.erase(seat.begin());
        int rowNum = stoi(seat);

        if(bus[rowNum][colNum] == 1){
            minTime--;
            totalTime -= cost[rowNum][colNum];
            bus[rowNum][colNum] = 0;
            cost[rowNum][colNum] = 0;
        }else{
            // need to set
            if((colNum == 0 && bus[rowNum][colNum+1] == 1) || (colNum == 3 && bus[rowNum][colNum-1] == 1)){
               cost[rowNum][colNum] = 3;
                totalTime += 3;
                minTime++;
            }else{
                cost[rowNum][colNum] = 1;
                totalTime +=1;
                minTime++;
            }
            bus[rowNum][colNum] = 1;
            

        }
        
        
    }
    
    int getTotalTime() {
        return totalTime;
        
    }
    
    int getMinTime() {
        return minTime;
        
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */