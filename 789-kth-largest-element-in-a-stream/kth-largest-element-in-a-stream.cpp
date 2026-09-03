class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int pq_size;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        pq_size = k;
        for(int i=0; i<k; i++)
        {   
            if(i<n)
                pq.push(nums[i]);
            else break;
        }

        for(int i=k; i<nums.size(); i++){
            if(i<n){
                if(nums[i] > pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else break;
            
        }      
        
    }
    
    int add(int val) {
        if(pq.empty() || pq_size > pq.size())
            pq.push(val);
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */