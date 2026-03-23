class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int, int>mp;
        for(auto a: nums)
            mp[a]++;
        
        vector<pair<int, int>>p;
        for(auto i: mp)
            p.push_back({i.second, i.first});

        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        for(int i=0; i<k; i++){
            ans.push_back(p[i].second);
        }
        return ans;
    }
};