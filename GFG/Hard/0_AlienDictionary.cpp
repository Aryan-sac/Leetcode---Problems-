/**
 * Problem Link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1
 * Platform     : GFG
 * Difficulty   : Hard
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
            // code here
            int totalChars = 0;    // Unique Characters count (k ki jagah totalChars use kiya)
            vector<bool> present(26, false);
            for (const string &word : words) {
                for (char c : word) {
                    if (!present[c - 'a']) {
                        present[c - 'a'] = true;
                        totalChars++;
                    }
                }
            }
            // Create Adjacency List
            vector<int> adj[26];
            vector<int> InDeg(26, 0);
            int n = words.size();

            for(int i=0; i<n-1; i++){
                string s1 = words[i], s2 = words[i+1];

                int j=0, k=0;
                while(j<s1.size() && k<s2.size()){
                    if(s1[j] != s2[k])
                    {
                        adj[s1[j]-'a'].push_back((s2[k]-'a'));
                        InDeg[s2[k]-'a']++;
                        break;
                    }
                    j++;
                    k++;
                }
            }   

            queue<int>q;

            for(int i=0; i<26; i++){
                if(!InDeg[i] && present[i])
                    q.push(i);
            }

            string AlienOrder = "";
            while(!q.empty()){
                int el = q.front();
                q.pop();
                AlienOrder += char(el + 'a');
                for(int i=0; i<adj[el].size(); i++){
                    InDeg[adj[el][i]]--;
                    if(!InDeg[adj[el][i]])
                        q.push(adj[el][i]);
                }
            }
            if(AlienOrder.length() < totalChars)
                return "";

            return AlienOrder;
        }
};
