class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;
                    break;
                }
            }
        }
        
        int uRow[4]={-1,0,1,0};
        int uCol[4]={0,1,0,-1};
        
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int boundary=0;
            
            for(int i=0;i<4;i++){
                int newRow=row+uRow[i];
                int newCol=col+uCol[i];
                
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m){
                    if(grid[newRow][newCol]==2)boundary++;
                    else if(grid[newRow][newCol]==1){
                        q.push({newRow,newCol});
                        grid[newRow][newCol]=2;
                        boundary++;}
                }
            }
            cnt+=(4-boundary);
            
            
        }
        return cnt;
    }
};