class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n, 0);
     // reverse all edges of the nodes
        for(int i=0; i<n; i++){
            // i -> it
            // it -> i
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
            }
        }
     // Apply TopoSort
     // count indegree for all nodes
        for(int i =0; i<n; i++){
            for(auto it : adjRev[i]){
                indegree[it]++;
            }
        }
     // insert all nodes in the queue which have indegree "0"
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};