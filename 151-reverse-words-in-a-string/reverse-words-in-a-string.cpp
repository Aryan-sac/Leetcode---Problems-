class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ') continue;
            string st = "";
            while(i<s.size() && s[i]!=' ')
            {
                st += s[i];
                i++;
            }
            reverse(st.begin(), st.end());
            ans += st +" ";
        }
        if(!ans.empty()) ans.pop_back(); // last space remove
        return ans;
    }
};