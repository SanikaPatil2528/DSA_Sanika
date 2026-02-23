class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int bestCity=-1;
        int bestCount=INT_MAX;

        for(int src=0;src<n;src++){
            vector<int>distance(n,INT_MAX);
            distance[src]=0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            pq.push({0,src});
            while(!pq.empty()){
                auto next=pq.top();
                pq.pop();
                int d=next.first;
                int node=next.second;
                if(d>distance[node]) continue;

                for(auto it:adj[node]){
                    int v=it.first;
                    int wt=it.second;

                    if(d+wt<distance[v]){
                        distance[v]=d+wt;
                        pq.push({distance[v],v});
                    }
                }
            }

            int count=0;
            for(int i=0;i<n;i++){
                if(i!=src && distance[i]<=distanceThreshold) count++;
            }

            if(count<=bestCount){
                bestCount=count;
                bestCity=src;
            }
        }

        return bestCity;
    }
};