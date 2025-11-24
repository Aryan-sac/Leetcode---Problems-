class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int>right(n,0);
        vector<int>left(n,0); 
        stack<int>st;

        // (i) right smaller nearest
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // (ii) left smaller nearest
        for(int i=0; i<n; i++){
            while(st.size()>0 && arr[st.top()] >= arr[i])
                st.pop();
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int CurrentArea = arr[i]*width;
            ans = max(ans, CurrentArea);
        }
        return ans;
    }
};