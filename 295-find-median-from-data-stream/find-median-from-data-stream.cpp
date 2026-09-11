class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty())
        {
            left.push(num);
            return;
        }
        if(num < left.top())
            left.push(num);
        else
            right.push(num);

        if(right.size() > left.size())
        {
            int n = right.top();
            right.pop();
            left.push(n);
        }
        if(left.size() > right.size()+1){
            int n = left.top();
            left.pop();
            right.push(n);
        }
    }
    
    double findMedian() {
        
        
        if(left.size() == right.size())
            return double(left.top() + right.top())/2;
        return (double)left.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */