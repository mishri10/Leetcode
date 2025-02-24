class Solution {
public:
    void Alice(int node,int parent,int sum,int&ans,vector<int>&amount,vector<int> adj[]){
        sum+=amount[node];
        bool check=false;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]!=parent){
                check=true;
                Alice(adj[node][i],node,sum,ans,amount,adj);
            }
        }
        if(!check)
        ans=max(ans,sum);
    }
    bool DFS(int node,int parent,vector<int>&bob_path,vector<int> adj[]){
        if(node==0){
            return 1;
        }
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]!=parent){
                if(DFS(adj[node][i],node,bob_path,adj)){
                    bob_path.push_back(node);
                    return 1;
                }
            }
        }
        return 0;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<int> adj[edges.size()+1];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>bob_path;
        DFS(bob,-1,bob_path,adj);
        int k=bob_path.size()/2;
        for(int i=k;i<bob_path.size();i++){
            amount[bob_path[i]]=0;
        }
        if(bob_path.size()%2==0){
            amount[bob_path[k-1]]/=2;
        }
        int ans=INT_MIN,sum=0;
        Alice(0,-1,sum,ans,amount,adj);
        return ans;
    }
};