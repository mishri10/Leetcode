class DisjointSet{
    
    public:
    vector<int>size,par;
    
    DisjointSet(int n){
        size.resize(n,1);
        par.resize(n,0);
        
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    
    int findUPar(int node){
        if(node==par[node])return node;
        
        return par[node]=findUPar(par[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)return;
        
        if(size[ulp_u]>size[ulp_v]){
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            
        }
        
        else{
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //step 1 join all 1's
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    int row=i,col=j;
                    for(int it=0;it<4;it++){
                        int newRow=row+dr[it];
                        int newCol=col+dc[it];
                        
                        if(newRow>=0 and newCol>=0 and newRow<n and newCol<n and 
                           grid[newRow][newCol]==1){
                            int node=row*n+col;
                            int adj_node=newRow*n+newCol;
                            ds.unionByRank(node,adj_node);
                        }
                    }
                }
            }
        }
        
        
        
        //step 2
        int ans=0;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    unordered_set<int>components;
                    for(int i=0;i<4;i++){
                        int newRow=row+dr[i];
                        int newCol=col+dc[i];
                        
                        
                        if(newRow>=0 and newCol>=0 and newRow<n and newCol<n and 
                           grid[newRow][newCol]==1){
                            components.insert(ds.findUPar(newRow*n+newCol));
                            
                        }
                    }
                    
                    int total_size=0;
                    for(auto it:components){
                        total_size+=ds.size[it];
                    }
                    
                    ans=max(ans,1+total_size);
                }
            }
        }
        
        for(int i=0;i<n*n;i++)
            ans=max(ans,ds.size[i]);
        return ans;
        
    }
};