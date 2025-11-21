class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int flag = 0;
        for(auto i : s){
            st.push(i);
            
            if(i=='}' || i==']' || i==')') 
            {  
                char ch = st.top();
                st.pop();
                if(st.empty()) return false;
                if(ch == '}' && st.top() == '{') st.pop();
                else if(ch == ')' && st.top() == '(') st.pop();
                else if(ch == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};