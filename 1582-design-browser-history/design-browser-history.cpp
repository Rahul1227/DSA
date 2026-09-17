class BrowserHistory {
private:
    string curr ="";
    stack<string> history;
    stack<string> future;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        while(!future.empty()) future.pop();
        history.push(curr);
        curr = url;

        
    }
    
    string back(int steps) {
        while(!history.empty() && steps--){
            future.push(curr);
            curr = history.top();
            history.pop();
        }
        return curr;
        
    }
    
    string forward(int steps) {
        while(!future.empty() && steps--){
            history.push(curr);
            curr = future.top();
            future.pop();
        }

        return curr;

        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */