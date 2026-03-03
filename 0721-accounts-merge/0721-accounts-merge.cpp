class DisjointSet{
public:
    vector<int>size,parent;

    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int findUParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ult_u=findUParent(u);
        int ult_v=findUParent(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);

        // mapping mails to node numbers
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()) mapMailNode[mail]=i;
                else ds.UnionBySize(i ,mapMailNode[mail]);
            }
        }

        // making list of mails as per ultimate parent
        vector<vector<string>> mergedMail(n);
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=it.second;
            mergedMail[ds.findUParent(node)].push_back(mail);
        }

        // final ans by adding names and sorting mails
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if (mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};