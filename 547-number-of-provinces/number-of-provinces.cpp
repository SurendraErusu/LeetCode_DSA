class Solution {
public:

    void dfs(vector<vector<int>>& adj, int node, vector<int> &vis) {
        vis[node] = 1;
        for(int neighbour : adj[node]) {
            if (vis[neighbour] == 0) {
                dfs(adj, neighbour, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis (n, 0);

        for (int u = 0; u < isConnected.size(); u++) {
            for (int v = 0; v < isConnected.size(); v++) {
                if (isConnected[u][v] == 1) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        for (int i =0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                dfs(adj, i, vis);
                count++;
            }
        } 
        return count;
    }
};