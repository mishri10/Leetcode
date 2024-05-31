class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        
        color[node]=col;
        
        for(auto adj_node: graph[node]){
            
            if(color[adj_node]==-1){
                if(dfs(adj_node,!col,color,graph)==0)return 0;
            }
            
            else if(color[adj_node]==col)return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==0)return 0;
            }
        }
        return 1;
    }
};