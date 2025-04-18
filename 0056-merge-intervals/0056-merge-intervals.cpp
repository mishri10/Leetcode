class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>end=intervals[0];
        vector<vector<int>>ans;

        int n= intervals.size();

        for(int i=1; i<n; i++){
            int last= end[1];
            if(intervals[i][0]<=last)
                end[1]=max(end[1],intervals[i][1]);
            else{
                ans.push_back(end);
                end=intervals[i];
            }
        }
        ans.push_back(end);
        return ans;

    }
};