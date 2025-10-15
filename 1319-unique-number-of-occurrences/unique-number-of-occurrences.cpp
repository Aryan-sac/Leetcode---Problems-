class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> mp;

    // strore freq in map
    for(auto el : arr){
        mp[el]++;
    }

    for(auto it = mp.begin(); it != mp.end(); ++it){
        int val = it->second;

        // store a num freq and make it 0
        it->second = 0;
        
        // the ckeck stored freq in a map
        for(auto it2 = mp.begin(); it2 != mp.end(); ++it2)
            if(it2->second == val) return false;
        it->second = val;
    }

    return true;
}
};