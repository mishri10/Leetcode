class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int maxStreak=0;


        for(auto i:s){
            if(s.count(i-1)==0){
                int streak=1;
                int curr=i;
                while(s.count(curr+1)>0){
                    streak++;
                    curr+=1;
                }
                maxStreak=max(maxStreak,streak);
            }
        }
        return maxStreak;
    }
};