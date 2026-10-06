/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
 * Platform     : GFG
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // 1. Adjacency list creation
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2. Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap priority queue storing {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated distances
            if (d > dist[node]) continue;

            // Traverse neighbors
            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int wt = neighbor.second;

                // Relaxation
                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
