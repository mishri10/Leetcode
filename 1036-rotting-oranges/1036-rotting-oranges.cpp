class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int fresh=0;

        int uRow[4]={-1,0,1,0};
        int uCol[4]={0,1,0,-1};

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]==2){
                    q.push({row,col});
                }

                else if(grid[row][col]==1)
                    fresh++;
                
            }
        }

        while(!q.empty()){
            int size= q.size();
            bool flag=0;

            for(int i=0; i<size; i++){
                int row=q.front().first;
                int col=q.front().second;

                q.pop();

                for(int j=0; j<4; j++){
                    int newRow=row+uRow[j];
                    int newCol=col+uCol[j];

                    if(newRow>=0 and newCol>=0 and newCol<m and newRow<n and
                        grid[newRow][newCol]==1){
                            flag=1;
                            grid[newRow][newCol]=2;
                            q.push({newRow,newCol});
                            fresh--;
                        }
                }

                
            }
            if(flag)
                time++;
        }
        if(fresh!=0)
            return -1;
        return time;
    }
};