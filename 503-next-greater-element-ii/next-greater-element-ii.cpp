class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);

        // copy same nums elements again
        // for(int i=0; i<n; i++){
        //     nums.push_back(nums[i]);
        // }

        stack<int>st;
        for(int i=(2*nums.size())-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i%n])
                st.pop();
            ans[i%n] = st.empty()?-1:nums[st.top()];
            st.push(i%n);
        }
        return ans;
    }
};