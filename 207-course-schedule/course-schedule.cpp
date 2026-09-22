class Solution {
public:
    bool dfs(int s, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
        visited[s] = 1;
        path[s] = 1;
        
        for (int i = 0; i < adj[s].size(); i++) {
            int neighbor = adj[s][i];
            if (visited[neighbor] == 0) {
                // If the recursive call finds a cycle, propagate true upward
                if (dfs(neighbor, adj, visited, path))
                    return true;
            }
            else if (path[neighbor] == 1) {
                // Cycle detected!
                return true;
            }
        }
        
        path[s] = 0; // Backtrack
        return false; // No cycle found from this path
    }

    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1]; // b_i is the prerequisite
            int v = edges[i][0]; // a_i is the dependent course
            adj[u].push_back(v); // Edge goes from b_i -> a_i
        }
        
        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // If a cycle is detected, we can't finish all courses -> return false
                if (dfs(i, adj, visited, path))
                    return false;
            }
        }
        return true; // No cycles found anywhere
    }
};