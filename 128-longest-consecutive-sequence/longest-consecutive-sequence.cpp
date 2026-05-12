class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res=0, count=1;
        unordered_set<int>s;
        for(auto a: nums)
            s.insert(a);
        for(auto it: s) {
            if(s.find(it - 1) == s.end()) {
                int curr = it;
                int count = 1;

                while(s.find(curr + 1) != s.end()) {
                    curr++;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};