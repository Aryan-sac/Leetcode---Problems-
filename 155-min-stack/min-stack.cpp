#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<long long int> st;
    long long int min_val;

public:
    MinStack() {
        min_val = INT_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min_val = val;
        } else {
            if(val < min_val){
                st.push((long long)2*val - min_val);
                min_val = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop() {
        if(st.top() < min_val){
            min_val = 2*min_val - st.top();
        }
        st.pop();
    }

    int top() {
        if(st.top() < min_val)
            return min_val;
        return st.top();
    }

    int getMin() {
        return min_val;
    }
};
