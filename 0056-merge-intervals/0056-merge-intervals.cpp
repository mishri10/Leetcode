class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        auto end=intervals[0];
        
        for(int i=1;i<n;i++){
            if(end[1]>=intervals[i][0]){
                end[1]=max(end[1],intervals[i][1]);
            }
            else{
                ans.push_back(end);
                end=intervals[i];
            }
        }
        ans.push_back(end);
        return ans;
    }
};