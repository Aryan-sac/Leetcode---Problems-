class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string el = s;
            sort(el.begin(), el.end());
            mp[el].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto i : mp) {
            res.push_back(i.second);
        }
        return res;
    }

};