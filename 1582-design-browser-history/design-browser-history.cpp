class BrowserHistory {
private:
    int currInd = -1;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currInd++;
        
    }
    
    void visit(string url) {
        history.resize(currInd+1);
        history.push_back(url);
        currInd++;
        
    }
    
    string back(int steps) {
        currInd = max(0, currInd - steps);
        return history[currInd];
        
    }
    
    string forward(int steps) {
        currInd = min((int)history.size()-1, currInd + steps);
        return history[currInd];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */