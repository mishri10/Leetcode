class DisjointSet{
    
    vector<int>size,par;
    
    public:
    DisjointSet(int n){
        size.resize(n);
        par.resize(n);
        
        for(int i=0;i<n;i++){
            size[i]=1;
            par[i]=i;
        }
    }
    
    
    int findUPar(int u){
        if(par[u]==u)return u;
        return par[u]=findUPar(par[u]);
    }
    
    void unionBySize(int u,int v){
        int ulpU=findUPar(u);
        int ulpV=findUPar(v);
        
        if(ulpU==ulpV)return;
        
        if(size[ulpU]>size[ulpV]){
            size[ulpU]+=size[ulpV];
            par[ulpV]=ulpU;
        }
        
        else{
            size[ulpV]+=size[ulpU];
            par[ulpU]=ulpV;
        }
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            ds.unionBySize(u,v);
        }
        
        return ds.findUPar(source)==ds.findUPar(destination);
        
        
    }
};