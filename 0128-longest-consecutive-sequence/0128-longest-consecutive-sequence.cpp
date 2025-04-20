class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;
        int cnt=0;
        int maxCnt=0;

        for(int i=0; i<nums.size(); i++){
            if(prev==INT_MIN){
                prev=nums[i];
                cnt=1;
            }
            else if(nums[i]==prev)
                continue;

            else if(nums[i]==prev+1){
                cnt++;
                prev=nums[i];
            }
            else{
                prev=nums[i];
                cnt=1;
            }

            maxCnt=max(maxCnt,cnt);
        }

        return maxCnt;

    }
};