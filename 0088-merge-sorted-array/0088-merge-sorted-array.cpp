class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt= n+m-1;
        int p1=m-1;
        int p2=n-1;

        while(p1>=0 and p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[pt]=nums1[p1];
                p1--;
            }
            else{
                nums1[pt]=nums2[p2];
                p2--;
            }
            pt--;
        }

        while(p2>=0){
            nums1[pt]=nums2[p2];
            p2--;
            pt--;
        }

    }
};
//[4,0,0,0,0,0] //[1,2,3,5,6]