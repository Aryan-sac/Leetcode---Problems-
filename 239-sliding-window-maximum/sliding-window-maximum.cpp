class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        int n = nums.size();
        
        for(int i=0; i<n; i++){

            // checking All Elements stored in dequeue of current window or NOT
            if(dq.size()>0 && dq.front()<=(i-k))
                dq.pop_front();
            
            // Storing max element at front of dequeue
            while(dq.size()>0 && nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};