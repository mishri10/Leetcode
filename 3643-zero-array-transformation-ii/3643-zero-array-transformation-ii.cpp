class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);
        int sum=0;
        int pos=0;

        for(int i=0; i<n; i++){
            while(diff[i]+sum<nums[i]){
                if(pos==queries.size())
                    return -1;
                int start= queries[pos][0];
                int end= queries[pos][1];
                int val= queries[pos][2];
                pos++;

                if(end<i)continue;

                diff[max(start,i)]+=val;
                if(end+1<n)diff[end+1]-=val;

            }
            sum+=diff[i];
        }
        return pos;
    }
};