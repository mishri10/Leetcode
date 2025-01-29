class DisjointSet{

    vector<int>par,size;
    public:
    DisjointSet(int n){
    par.resize(n+1);
    size.resize(n+1);
    for(int i=0; i<=n; i++){
        par[i]=i;
        size[i]=1;
    }
    }

    

    int findUPar(int u){
        if(u==par[u])
            return u;

        return par[u]=findUPar(par[u]);
    }

    void unionBySize(int u, int v){
        int ulpU=findUPar(u);
        int ulpV=findUPar(v);
        if(ulpU==ulpV)
            return;

        if(size[ulpU]>=size[ulpV]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);

        int ans=0;

        for(int i=0; i<n; i++){
            int u=edges[i][0];
            int v=edges[i][1];

            int ulpU= ds.findUPar(u);
            int ulpV= ds.findUPar(v);

            if(ulpU==ulpV){
                ans=i;
            }

            else{
                ds.unionBySize(u,v);
            }
        }
        return edges[ans];
    }
};