class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>occurence((n*m)+1);
        vector<int>rowFreq(n,0);
        vector<int>colFreq(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                occurence[mat[i][j]]={i,j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int row= occurence[arr[i]].first;
            int col= occurence[arr[i]].second;
            
            rowFreq[row]++;
            colFreq[col]++;

            if(rowFreq[row]==m or colFreq[col]==n)
                return i;
        }
        return 0;
    }
};