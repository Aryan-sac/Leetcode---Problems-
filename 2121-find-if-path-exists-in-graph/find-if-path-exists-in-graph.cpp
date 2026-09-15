class Solution {
public:
    bool dfs(int s, int d, vector<vector<int>>&adj, vector<int>&visited){
        if(s == d)
            return true;
        // visited[s]=1;
        for(int i=0; i<adj[s].size(); i++){
            if(visited[adj[s][i]] == 0){
                visited[s] = 1;
                if(dfs(adj[s][i], d, adj, visited))
                    return true;
            }
            
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n, 0);
        return dfs(source, destination, adj, visited);
    }
};