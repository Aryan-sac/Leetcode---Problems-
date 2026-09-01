class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x: stones)
            pq.push(x);

        while(pq.size() > 1){
            int el1 = pq.top();
            pq.pop();
            int el2 = pq.top();
            pq.pop();

            pq.push(abs(el1-el2));
        }
        return pq.top();
    }
};