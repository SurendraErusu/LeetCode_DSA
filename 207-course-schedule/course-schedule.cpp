class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
           vector<int> indegree(numCourses);
           vector<int> vis(numCourses, 0);
           vector<int> topo;
           queue<int> q;

           for (auto pair : prerequisites) {
            adj[pair[0]].push_back(pair[1]);
           }
        
            for (int i = 0; i < adj.size(); i++) {
                for (int neighbour : adj[i]) {
                    indegree[neighbour]++;
                }
            }

            for (int i  = 0; i < indegree.size(); i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                topo.push_back(node);
                for (int neighbour : adj[node]) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }

            if (numCourses == topo.size()) return true;

            return false;

    }
};