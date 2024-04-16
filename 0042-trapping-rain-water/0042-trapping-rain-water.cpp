class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        int right=n-1;
        int leftmax=0,rightmax=0;
        int ans=0;
        
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(arr[left]>=leftmax)leftmax=arr[left];
                else ans+= (leftmax-arr[left]);
                left++;
            }
            
            else{
                if(arr[right]>=rightmax)rightmax=arr[right];
                else ans+= (rightmax-arr[right]);
                right--;
            }
        }
        return ans;
    }
};