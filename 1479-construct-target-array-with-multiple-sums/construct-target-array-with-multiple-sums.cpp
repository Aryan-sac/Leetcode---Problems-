class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long totalSum = 0;
        priority_queue<int>pq;
        for(auto x: target){
            pq.push(x);
            totalSum += x;
        }
        while(pq.top() != 1)
        {
            long long remSum = totalSum - pq.top();
            if(remSum<=0 || remSum >= pq.top())
                return false;
            totalSum -= pq.top();
            int val = pq.top() % remSum;
            if(val==0 && remSum!=1)
                return false;
            totalSum += val;
            pq.pop();
            pq.push(val);
        }

        return true;
    }
};