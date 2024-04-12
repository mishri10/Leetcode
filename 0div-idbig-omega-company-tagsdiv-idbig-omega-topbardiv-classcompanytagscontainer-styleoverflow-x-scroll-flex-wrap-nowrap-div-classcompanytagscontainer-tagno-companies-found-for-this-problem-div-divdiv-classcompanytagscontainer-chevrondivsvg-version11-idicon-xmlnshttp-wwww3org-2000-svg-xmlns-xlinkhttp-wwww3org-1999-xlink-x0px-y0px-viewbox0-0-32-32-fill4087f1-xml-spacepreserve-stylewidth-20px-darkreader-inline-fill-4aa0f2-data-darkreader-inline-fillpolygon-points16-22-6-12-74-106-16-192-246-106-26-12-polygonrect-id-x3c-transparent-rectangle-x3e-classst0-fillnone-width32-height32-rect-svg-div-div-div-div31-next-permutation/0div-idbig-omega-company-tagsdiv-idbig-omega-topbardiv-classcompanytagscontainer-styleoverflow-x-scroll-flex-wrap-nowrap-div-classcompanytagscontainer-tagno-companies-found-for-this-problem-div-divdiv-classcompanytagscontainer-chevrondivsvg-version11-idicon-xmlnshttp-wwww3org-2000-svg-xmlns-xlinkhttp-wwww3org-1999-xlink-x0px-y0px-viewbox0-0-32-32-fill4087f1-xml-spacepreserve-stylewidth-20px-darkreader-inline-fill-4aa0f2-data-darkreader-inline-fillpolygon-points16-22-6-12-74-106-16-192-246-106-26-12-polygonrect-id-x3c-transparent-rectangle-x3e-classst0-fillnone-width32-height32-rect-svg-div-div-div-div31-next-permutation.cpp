class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
// T.C: The next_permutation() function takes O(N) time to find the next permutation and there are N! number of permutations for an array of size N. Auxiliary Space: O(1) No auxiliary space is used.