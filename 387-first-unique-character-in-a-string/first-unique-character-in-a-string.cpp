class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        int found = 0;
        for(char i: s)
            mp[i]++;
        
        for (int i = 0; i < n; i++) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};