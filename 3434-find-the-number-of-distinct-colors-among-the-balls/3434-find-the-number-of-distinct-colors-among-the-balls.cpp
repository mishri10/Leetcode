class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>mp;
        unordered_map<int,int>col;

        for(int i=0; i<queries.size(); i++){
                if(mp.find(queries[i][0])!=mp.end()){
                    col[mp[queries[i][0]]]--;
                    if(col[mp[queries[i][0]]]==0)
                        col.erase(mp[queries[i][0]]);
                }
            mp[queries[i][0]]=queries[i][1];
            col[queries[i][1]]++;
            ans.push_back(col.size());

        }
        return ans;
    }
};
//0->1  //1->1
//1->1  //4->1