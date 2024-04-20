class Solution {
public:
    int uRow[4]={-1,0,1,0};
    int uCol[4]={0,1,0,-1};
    void dfs(int row,int col, vector<vector<int>>& land, int& endRow,int& endCol ){
        
        endRow=max(endRow,row);
        endCol=max(endCol,col);
        
        land[row][col]=2;
        
        for(int i=0;i<4;i++){
            int newRow=row+uRow[i];
            int newCol=col+uCol[i];
            
            if(newRow>=0 and newRow<land.size() and newCol>=0 and 
               newCol<land[0].size() and land[newRow][newCol]==1){
                dfs(newRow,newCol,land,endRow,endCol);
            }
        }
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        
        int n=land.size();
        int m=land[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    vector<int>temp;
                
                    int endRow=i;
                    int endCol=j;
                    dfs(i,j,land,endRow,endCol);
                    
                    ans.push_back({i,j,endRow,endCol});
                    
                }
            }
        }
        
        return ans;
        
    }
};