class Solution {
  public:
    bool dfs(int s, vector<vector<int>>&adj, vector<int>&visited, vector<int>&path){

            visited[s] = 1;
            path[s] = 1;
            for(int i=0; i<adj[s].size(); i++){
                if(visited[adj[s][i]] == 0){
                    if(dfs(adj[s][i], adj, visited, path))
                        return true;
                }
                else if(path[adj[s][i]] == 1)
                    return true;
            }
            path[s] = 0;
            return false;
        }
        bool isCyclic(int V, vector<vector<int>>& edges) {
            // Code here
            int n = edges.size();
            vector<vector<int>>adj(V);
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
            }
            vector<int>visited(V, 0);
            vector<int>path(V, 0);
            for (int i = 0; i < V; i++) {
                    if (!visited[i]) {
                        if (dfs(i, adj, visited, path))
                         return true;
                }
            }
            return false;
        }
};