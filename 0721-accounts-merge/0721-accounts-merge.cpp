class Solution {
private:
    int findUPar(int node,vector<int>&par){
        if(par[node]==node) return node;
        return par[node]=findUPar(par[node],par);
    }
    void unionBySize(int u,int v,vector<int>&size,vector<int>&par){
        int up_u=findUPar(u,par);
        int up_v=findUPar(v,par);
        if(up_u==up_v) return ;
        if(size[up_u]<size[up_v]){
            par[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            par[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>size(n,1);
        vector<int>par(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        
        unordered_map<string,int> mailMap;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mailMap.find(accounts[i][j])==mailMap.end()) mailMap[accounts[i][j]]=i;
                else unionBySize(mailMap[accounts[i][j]],i,size,par);
            }
        }

        vector<vector<string>>mergedMails(n);
        for(auto it: mailMap){
            mergedMails[findUPar(it.second,par)].push_back(it.first);
        }

        vector<vector<string>>ans;
        for(int i=0;i<mergedMails.size();i++){
            if(mergedMails[i].size()==0) continue;
            sort(mergedMails[i].begin(),mergedMails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),mergedMails[i].begin(),mergedMails[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};