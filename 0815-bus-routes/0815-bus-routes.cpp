class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;

        unordered_map<int,vector<int>>stopToBus;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                stopToBus[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({source,0});

        unordered_set<int>visStops;
        unordered_set<int>visBuses;
        visStops.insert(source);

        while(!q.empty()){
            auto [currStop,busesTaken]=q.front();
            q.pop();
            if(currStop==target) return busesTaken;

            // board every bus available at this stop
            for(int bus:stopToBus[currStop]){
                if(visBuses.count(bus)) continue;

                visBuses.insert(bus);

                // travel to every stop of this bus
                for(int nextStop:routes[bus]){
                    if(!visStops.count(nextStop)){
                        visStops.insert(nextStop);
                        q.push({nextStop,busesTaken+1});
                    }
                }
            }
        }

        return -1;
    }
};