class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>color(n,-1);
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            
            if(color[i]==-1){
                
                q.push({i,0});
                
                
                while(!q.empty()){
                    
                    int node=q.front().first;
                    int col=q.front().second;
                    color[node]=col;
                    q.pop();
                    
                    for(auto adj_node: graph[node]){
                        
                        if(color[adj_node]==-1){
                            q.push({adj_node,!col});                          
                            
                        }
                        else if(color[adj_node]==col)return 0;
                        
                    }
                }
            }
        }
        return 1;
    }
};