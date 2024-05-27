class Solution {
public:
//     int greater(int target,vector<int>& nums){
//         int start=0;
//         int end=nums.size()-1;
//         int ind=0;
        
//         while(start<=end){
//             int mid= start+ (end-start)/2;
            
//             if(nums[mid]>=target){
//                 ind=mid;
//                 end=mid-1;
//             }
//             else start=mid+1;
//         }
        
//         return nums.size()-ind;
        
//     }
    
    int greater(int target,vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                ans=nums.size()-i;
                break;
            }
        }
        return ans;
    }
    
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        int end=1001;
      
        
        while(start<=end){
            int mid = start+ (end-start)/2;
            
            int cnt=greater(mid, nums);
            
            if(cnt==mid)return mid;
            
            else if(cnt<mid){
                
                end=mid-1;
            }
            else start=mid+1;
        }
        return -1;
    }
};