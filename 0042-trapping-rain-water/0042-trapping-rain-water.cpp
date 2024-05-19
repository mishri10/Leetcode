class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix(n), suffix(n);
        int maxiL=0, maxiR=0;
        for(int i=0;i<n;i++){
            if(height[i]>maxiL)maxiL=height[i];
            prefix[i]=maxiL;
        }
        
        for(int i=n-1;i>=0;i--){
            if(height[i]>maxiR)maxiR=height[i];
            suffix[i]=maxiR;
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(prefix[i],suffix[i])-height[i]);
        }
        return ans;
        
        
        
        
    }
};