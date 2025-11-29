class MyQueue {
public:
    stack<int>st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int val;
        stack<int>st2;
        // storing elements from st1 to st2
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        // storing (pop value)/(Last value) of st1 stack in st2 
        val = st2.top();
        st2.pop();
        // storing back elements from st2 to st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        int val;
        stack<int>st2;
        // storing elements from st1 to st2
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        // storing (pop value)/(Last value) of st1 stack in st2 
        val = st2.top();
        // storing back elements from st2 to st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    bool empty() {
        return st1.empty();
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