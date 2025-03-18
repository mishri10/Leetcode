class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen=0;
        int start=0;
        int mask=0;

        for(int end=0; end<nums.size(); end++){
            while((mask&nums[end])!=0){
                mask^= nums[start];
                start++;
            }

            mask|=nums[end];
            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};