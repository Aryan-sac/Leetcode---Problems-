class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        stack<int>st;
        st.push(0);
        vector<int>visited(adj.size(), 0);
        vector<int>res;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(visited[x] == 0)
            {
                res.push_back(x);
                visited[x] = 1;
                for(int i=adj[x].size()-1; i>=0; i--){
                    if(visited[adj[x][i]] == 0)
                        st.push(adj[x][i]);
                }
            }
        }
        return res;
    }
};
