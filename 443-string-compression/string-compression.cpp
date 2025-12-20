class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(),count,idx=0;
        char ch;
        for(int i=0 ;i<n ;i++){
            count = 0;
            ch = chars[i];
            while((i<n) && (chars[i] == ch))
            {
                count++;
                i++;
            }
            if(count == 1)
                chars[idx++] = ch;
            if(count > 1)
            {   
                chars[idx++] = ch;
                string str = to_string(count);  // convert count into string
                for(char dgt: str){             // seperating each digit of that string str
                    chars[idx++] = dgt;
                }
            }
            i--;
        }
        return idx;
    }
};