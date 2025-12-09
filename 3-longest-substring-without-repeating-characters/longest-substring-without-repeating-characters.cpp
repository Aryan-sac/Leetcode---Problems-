class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        
        int count=0, i=0, j=0;
        while(i<s.length() && j<s.length()){
            if(mp.find(s[j]) == mp.end())
            {
                mp[s[j]]++;
                j++;
                count = max(count, j-i);
            }
            else{
                mp.erase(s[i]);
                i++;
            }
        }
        return count;
    }
};