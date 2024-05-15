class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size(),m=nums2.size();
        
        
        
        int low=0, high=n;
      
        
        while(low<=high){
            int mid1= low+(high-low)/2;
            int mid2= ((n+m+1)/2)- mid1;
            
            int l1= INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            
            if(mid1-1>=0)l1=nums1[mid1-1];
            if(mid2-1>=0)l2=nums2[mid2-1];
            
            if(mid1<n)r1=nums1[mid1];
            if(mid2<m)r2=nums2[mid2];
            
            
            if(l1<=r2 and l2<=r1){
                if((n+m)%2==0){
                int a=max(l1,l2);
                int b=min(r1,r2);
                return (double)(a+b)/2;
            }
                else return max(l1,l2);}
            
            else if(l2>r1)low=mid1+1;
            else high=mid1-1;
        }
        return -1;
    }
};