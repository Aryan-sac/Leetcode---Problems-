class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        for(int i=0; i<n; i++)
            pq.push({matrix[i][0], {i, 0}});

        for(int i=1; i<k; i++){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(col+1 < n)
            pq.push({matrix[row][col+1], {row, col+1}});
        }
        return pq.top().first;
    }
};