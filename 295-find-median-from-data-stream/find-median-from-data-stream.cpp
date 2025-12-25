class MedianFinder {
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        int maxLen = maxHeap.size();
        int minLen = minHeap.size();

        if(maxLen - minLen >= 2){
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);

        }
        if (minLen - maxLen >=1){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
        }
        
    }
    
    double findMedian() {
        int maxLen = maxHeap.size();
        int minLen = minHeap.size();
        if(maxLen > minLen){
            return maxHeap.top();
        }else{
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            cout<<maxTop<<" "<<minTop;
            double ans = 1.0 * (maxTop + minTop) / 2.0;
            return ans;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */