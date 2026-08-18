class Solution {
public:
    vector<vector<string>>res;
    bool isPal(string s, int st, int end){
        while(st<=end){
            if(s[st++] != s[end--])
                return false;
        }
        return true;
    }
    void helper(string s, int idx, vector<string>ans){

        if(idx == s.length())
        {
            res.push_back(ans);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            if(isPal(s, idx, i)){
                ans.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<string>ans;
       helper(s, 0, ans);
       return res;
     
    }
};