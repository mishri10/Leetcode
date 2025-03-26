class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                temp.push_back(grid[i][j]);
            }
        }


        sort(temp.begin(),temp.end());
        int median= temp[temp.size()/2];
        int ans=0;

        for(auto i: temp){
            int diff= abs(i-median);
            if(diff%x != 0) return -1;
            ans+= (diff/x);
        }
        return ans;
    }
};
