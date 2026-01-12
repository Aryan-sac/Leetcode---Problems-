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
            int idx = q.front();
            q.pop();
            
            tickets[idx]--;
            time++;
            
            if(idx == k && tickets[idx] == 0) {
                return time;
            }
            
            if(tickets[idx] > 0) {
                q.push(idx);
            }
        }
        return time;
    }

};