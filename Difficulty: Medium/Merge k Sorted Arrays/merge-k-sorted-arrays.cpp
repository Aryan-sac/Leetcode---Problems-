class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int,int>>>>pq;
        int n = mat.size();
        pair<int, pair<int, int>>el;
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (!mat[i].empty()) {
                pq.push({mat[i][0], {i, 0}});
            }
        }  
        while(!pq.empty()){
            el = pq.top();
            pq.pop();
            ans.push_back(el.first);
            int i = el.second.first;
            int j = el.second.second;
            if(j + 1 < mat[i].size())
                pq.push({mat[i][j+1], {i, j+1}});
            
                
        }
        
        return ans;
    }
};