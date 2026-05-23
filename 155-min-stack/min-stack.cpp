class MinStack {
    stack<pair<int, int>> st;
    int min_val;

public:
    MinStack() {
        min_val = INT_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
            min_val = val;
        } else {
            min_val = min(val, st.top().second);
            st.push({val, min_val});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */