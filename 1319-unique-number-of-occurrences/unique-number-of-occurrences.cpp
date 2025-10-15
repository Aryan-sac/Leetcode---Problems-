class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> mp;
    for(auto el : arr){
        mp[el]++;
    }

    for(auto it = mp.begin(); it != mp.end(); ++it){
        int val = it->second;
        it->second = 0;
        for(auto it2 = mp.begin(); it2 != mp.end(); ++it2)
            if(it2->second == val) return false;
        it->second = val;
    }

    return true;
}
};