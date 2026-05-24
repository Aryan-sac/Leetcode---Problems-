class MyQueue {
public:
    MyQueue() {
    }
    queue<int> q1;

    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int peek() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
