class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int ele1=INT_MAX, ele2=INT_MAX;
        int n=nums.size();
        
        
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 and nums[i]!=ele2){
                cnt1++;
                ele1=nums[i];
            }
            else if(cnt2==0 and nums[i]!=ele1){
                cnt2++;
                ele2=nums[i];
            }
            else if(ele1==nums[i])cnt1++;
            else if(ele2==nums[i])cnt2++;
            
            else {
                cnt1--;
                cnt2--;
            }
            
        }
        
        cnt1=0;
        cnt2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)cnt1++;
            else if(nums[i]==ele2)cnt2++;
        }
        
        if(cnt1>n/3 and cnt2>n/3)return {ele1,ele2};
        else if(cnt1>n/3)return {ele1};
        else if(cnt2>n/3)return {ele2};
        return {};
    }
};