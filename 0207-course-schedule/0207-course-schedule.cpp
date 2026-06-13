class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0) q.push(i);
        
        int topoSize=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topoSize++;
            for(auto neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        if(topoSize<numCourses) return false;
        return true;
    }
};