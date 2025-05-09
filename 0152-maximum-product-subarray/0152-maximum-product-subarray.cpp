#define ll long long int
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll pre=1;
        ll suf=1;
        ll ans=INT_MIN;
        
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(pre==0)
                pre=1;
            if(suf==0)
                suf=1;
            
            if(pre*10<INT_MAX)pre*=nums[i];
            if(suf*10<INT_MAX)suf*=nums[n-i-1];
            
            ans=max(ans,pre);
            ans=max(ans,suf);            
            
        }
        
        return ans;
    }
};