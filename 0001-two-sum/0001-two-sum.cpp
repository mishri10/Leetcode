class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        unordered_map<int,int>numIdx;
        
        for(int i=0;i<nums.size();i++){
            if(numIdx.find(target-nums[i])!=numIdx.end()){
                return {i,numIdx[target-nums[i]]};
            }
            numIdx[nums[i]]=i;
        }
        
        return {-1,-1};
    }
};
// 26
// [2,7,11,15]

//[3,2,4]

// 7
//[2,3,4]  
     // i j
   
   // sum<target--> i++;
   // sum>target--> j--;
   // sum==target--> return {i,j};

    //T.c: O(nlogn)+O(N)
    //S.C: O(1) --> excluding the answer vector

//  [2,7,11,15]
// target=26
// 2-->0, 7-->1, 11-->2, 
// x+curr_num=target
// x=target-curr_num
//T.C: O(N)
//S.C: O(N) 

