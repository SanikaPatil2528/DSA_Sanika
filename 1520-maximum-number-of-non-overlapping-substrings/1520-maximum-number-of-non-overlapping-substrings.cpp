class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node])
            if (!vis[it]) dfs(it,adj,vis,st);
        st.push(node);
    }

    void revDfs(int node,vector<vector<int>>&revAdj,vector<int>&vis,vector<int>&component){
        vis[node]=1;
        component.push_back(node);
        for(auto it:revAdj[node]){
            if(!vis[it]) revDfs(it,revAdj,vis,component);
        }
    }

    static bool compareEnd(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        // interval for each character
        vector<int> first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            if(first[c]==-1) first[c]=i;
            last[c]=i;
        }

        // dependency graph
        vector<vector<int>> adj(26);
        for(int c=0;c<26;c++){
            if (first[c]==-1) continue; // not present in string
            for(int i=first[c];i<=last[c];i++){
                int d=s[i]-'a';
                if(d!=c) adj[c].push_back(d);
            }
        }

        // Run Kosaraju to get SCC's (strongly connected components)
        stack<int>st;
        vector<int>vis(26,0);
        // get finishing order
        for(int i=0;i<26;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        // reverse graph
        vector<vector<int>> revAdj(26);
        for(int i=0;i<26;i++){
            vis[i]=0; // we need vis again when we do dfs
            for(auto it:adj[i])
                revAdj[it].push_back(i);
        }
        // dfs as per finish time
        vector<vector<int>> scc;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            vector<int>component;
            if(!vis[node]) revDfs(node,revAdj,vis,component);
            scc.push_back(component);
        }

        // build interval for each scc
        vector<pair<int,int>> intervals;
        for(auto &comp:scc){
            int start=INT_MAX;
            int end=-1;
            for (auto c:comp){
                if (first[c]==-1) continue;
                start=min(start,first[c]);
                end=max(end,last[c]);
            }
            if(end!=-1) intervals.push_back({start,end});
        }

        // remove invalid intervals
        vector<pair<int,int>>valid;
        for(auto p:intervals){
            int l=p.first;
            int r=p.second;
            bool ok=true;
            for(int i=l;i<=r;i++){
                int c=s[i]-'a';
                if(first[c]<l){
                    ok=false;
                    break;
                }
            }

            if(ok) valid.push_back({l,r});
        }

        // Greedy Selection
        // goal -> max no of substrings, no overlap
        // smallest finish time first
        sort(valid.begin(),valid.end(),compareEnd);
        vector<string>ans;
        int prevEnd=-1;

        for(auto [l,r]:valid){
            if(l>prevEnd){
                ans.push_back(s.substr(l,r-l+1));
                prevEnd=r;
            }
        }

        return ans;
    }
};