class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> q;
        int n = tickets.size();
        
        for(int i=0; i<n; i++) {
            q.push(i);
        }
        
        while(tickets[k]>0) {
            int val = q.front();
            q.pop();
            
            tickets[val]--;
            time++;
            
            if(val == k && tickets[val] == 0) {
                return time;
            }
            
            if(tickets[val] > 0) {
                q.push(val);
            }
        }
        return time;
    }

};