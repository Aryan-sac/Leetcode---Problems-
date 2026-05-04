class Solution {
public:
    long long countSubstrings(string s, char c) {
        long count=0;
        for(auto a: s){
            if(a==c)count++;
        }
        return count*(count+1)/2;
    }
};