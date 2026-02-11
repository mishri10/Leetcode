class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row=0; row<numRows; row++){
            vector<int>temp(row+1,1);
            for(int col=1; col<=row-1; col++){
                temp[col]=ans[row-1][col]+ans[row-1][col-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};