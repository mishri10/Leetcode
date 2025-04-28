class Solution {
public:
    bool dfs(int node,vector<int>& color, int col, vector<vector<int>>& adj){
        color[node]=col;

        for(auto adjNode: adj[node]){
            if(color[adjNode]==-1){
                if(dfs(adjNode,color,!col,adj)==0)
                    return 0;
            }
            else if(color[adjNode]==col)
                return 0;
        }
        return 1;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        int col=0;

        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(dfs(i,color,col,graph)==0)
                    return 0;
            }
        }
        return 1;
    }
};