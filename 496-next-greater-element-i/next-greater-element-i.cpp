class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[i] > st.top()) st.pop();
            if(st.empty()) mp[arr[i]] = -1;
            else mp[arr[i]] = st.top();
            st.push(arr[i]);
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};