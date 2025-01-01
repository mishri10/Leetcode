class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>ngeRight(n);
        vector<int>ngeLeft(n);
        int ans=0;
        ngeLeft[0]=height[0];
        ngeRight[n-1]=height[n-1];

        for(int i=1; i<n; i++)
            ngeLeft[i]=max(height[i],ngeLeft[i-1]);
        
        for(int i=n-2; i>=0; i--)
            ngeRight[i]=max(height[i],ngeRight[i+1]);
        

        for(int i=0; i<n; i++){
            int possibleHeight= min(ngeRight[i],ngeLeft[i]);
            ans+= (possibleHeight-height[i]);
        }

        return ans;
    }
};