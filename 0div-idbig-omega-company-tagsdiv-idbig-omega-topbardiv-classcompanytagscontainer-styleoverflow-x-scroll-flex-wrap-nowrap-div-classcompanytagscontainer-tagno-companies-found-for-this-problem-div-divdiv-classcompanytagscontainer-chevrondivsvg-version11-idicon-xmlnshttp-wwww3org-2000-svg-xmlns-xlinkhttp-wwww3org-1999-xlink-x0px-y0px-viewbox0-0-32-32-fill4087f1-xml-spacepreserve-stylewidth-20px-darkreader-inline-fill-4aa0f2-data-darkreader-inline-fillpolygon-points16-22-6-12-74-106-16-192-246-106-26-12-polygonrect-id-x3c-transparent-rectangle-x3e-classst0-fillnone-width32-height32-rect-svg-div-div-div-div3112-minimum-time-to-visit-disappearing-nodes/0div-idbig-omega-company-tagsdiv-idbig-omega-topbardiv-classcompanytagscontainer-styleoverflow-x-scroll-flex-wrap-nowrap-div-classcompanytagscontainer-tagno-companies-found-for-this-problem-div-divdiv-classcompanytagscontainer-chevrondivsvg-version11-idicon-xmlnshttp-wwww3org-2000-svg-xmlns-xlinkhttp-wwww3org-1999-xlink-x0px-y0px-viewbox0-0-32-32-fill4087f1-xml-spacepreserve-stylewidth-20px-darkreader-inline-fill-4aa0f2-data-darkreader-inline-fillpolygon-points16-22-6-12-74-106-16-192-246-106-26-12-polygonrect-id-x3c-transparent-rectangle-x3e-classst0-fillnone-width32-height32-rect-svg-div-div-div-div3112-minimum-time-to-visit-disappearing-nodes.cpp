class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(n,1e8);
        dis[0]=0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            if(dis[node]<distance or distance>=disappear[node])continue;
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                
                if(distance+wt<dis[v]){
                    dis[v]=distance+wt;
                    pq.push({dis[v],v});
                }
                    
            }
        }
        
        for(int i=0;i<n;i++){
            if(dis[i]>=disappear[i] or dis[i]==1e8)dis[i]=-1;
        }
        return dis;
    }
};