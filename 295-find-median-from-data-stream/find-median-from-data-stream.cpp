class MedianFinder {
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
public:
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        if(firstHalf.empty() || num < firstHalf.top()){
            firstHalf.push(num);
        }else{
            secondHalf.push(num);
        }

        int firstN = firstHalf.size();
        int secondN = secondHalf.size();
        if(firstN - secondN > 1){
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }else if(secondN > firstN){
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
        
        
    }
    
    double findMedian() {
        if(firstHalf.size() > secondHalf.size()){
            return firstHalf.top();
        }else{
            return (firstHalf.top()*1.00000 + secondHalf.top())/2;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */