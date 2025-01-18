class Solution {
public:
    int minCost(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};

        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
    

        while(!pq.empty()){
            int cost=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(vis[row][col]==1)
                continue;

            if(row==n-1 and col==m-1)
                return cost;

            vis[row][col]=1;

            for(int i=0; i<4; i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];

                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
                    !vis[newRow][newCol]){
                    if(i+1==grid[row][col])
                        pq.push({cost,{newRow,newCol}});
                       
                    
                    else
                        pq.push({cost+1,{newRow,newCol}});
                }
            }
        }
        return 0;
    }
};