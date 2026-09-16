class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int max_el = INT_MIN;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            max_el = max(max_el, nums[i][0]);
        }
        ans.push_back(pq.top().first);
        ans.push_back(max_el);

        int diff = ans[1]-ans[0];

        while(pq.size() == nums.size()){
            int val = pq.top().first;
            int i = pq.top().second.first;  // row
            int j = pq.top().second.second; // element idx of that row OR column
            pq.pop();

            if(j+1 < nums[i].size()){
                pq.push({nums[i][j+1], {i, j+1}});
                max_el = max(max_el, nums[i][j+1]);
                int min_el = pq.top().first;
                if(max_el - min_el < diff){
                    diff = max_el-min_el;
                    ans[0] = min_el;
                    ans[1] = max_el;
                }
            }
            else break;

        }
        return ans;
    }
};