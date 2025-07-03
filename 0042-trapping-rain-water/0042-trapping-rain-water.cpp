class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0;
        int rightMax=0;
        int ans=0;

        int left=0;
        int right=height.size()-1;

        while(left<=right){
            if(leftMax<rightMax){
                if(leftMax>=height[left]){
                    ans+=(leftMax-height[left]);
                }
                else
                    leftMax=height[left];
                
                left++;
            }

            else{
                if(rightMax>=height[right])
                    ans+=(rightMax-height[right]);
                    
                else
                    rightMax=height[right];

                right--;
                
            }
        }


            return ans;
        
    }
};
//[0,1,0,2,1,0,1,3,2,1,2,1]
//[0,1,1,2,2,2,2,3,3,3,3,3] --> previous greater element
//[3,3,3,3,3,3,3,3,2,2,2,1] --> next greater element
//[-,1,1,2,2,2,2,3,2,2,2,-] --> minium of greater elements on both side
//[-,0,1,0,1,2,1,0,0,1,0,-] --> min of greater neighbour - height
// ans=6

// T.C: O(N) //S.C: O(2N) --> brute force approch


//optimal approch --> 2 pointer
// as we want min from either left and right that would only be contributing to my ans


//left=0 , right=n-1
//[0,1,0,2,1,0,1,3,2,1,2,1]
//             l r
//leftMax=2; rightMax=3;
//ans=6
