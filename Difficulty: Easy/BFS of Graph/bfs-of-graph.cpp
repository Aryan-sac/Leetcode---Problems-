class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int>q;
        q.push(0);
        vector<int>ans;
        vector<int>visited(adj.size(), 0);
        while(!q.empty()){
            if(visited[q.front()] == 0)
            {
                ans.push_back(q.front());
                visited[q.front()] = 1;
                for(int i=0; i<adj[q.front()].size(); i++)
                    q.push(adj[q.front()][i]);
                q.pop();
            }
            else{
                q.pop();
            }
        }
        return ans;
    }
};