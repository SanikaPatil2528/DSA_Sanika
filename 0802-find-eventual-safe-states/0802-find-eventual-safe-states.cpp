class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 1. reverse graph
        vector<vector<int>>revAdj(graph.size());
        vector<int>indegree(graph.size(),0);

        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int>safe_nodes;
        queue<int>q;

        // 2.terminal node --> safe
        for(int i=0;i<indegree.size();i++){
            if (indegree[i]==0){
                safe_nodes.push_back(i);
                q.push(i);
            }
        }

        // 3.topo sort 
        // we check all paths possible from terminal to nodes which would be safe node
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    safe_nodes.push_back(it);
                }
            }
        }

        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};