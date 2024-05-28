class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            diff[i]=abs(s[i]-t[i]);
        }
        
        int ans=0;
        int curr_sum=0;
        
        int left=0,right=0;
        
        while(right<n){
            while(curr_sum>maxCost){
                curr_sum-=diff[left];
                left++;
            }
            
            curr_sum+=diff[right];
            
            if(curr_sum<=maxCost){
                ans=max(right-left+1,ans);
                
            }
            right++;
        }
        return ans;
        
    }
};