class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int n = nums.size();
    int result = 0;

    for (int i = 31; i >= 0; i--) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if ((nums[j] & (1 << i)) != 0) {
                count++;
            }
        }

        int currentBit = (k & (1 << i)) != 0;

        if (count % 2 != currentBit) {
            if (count > 0 || currentBit) {
                result++;
            }

            for (int j = 0; j < n; j++) {
                nums[j] ^= (1 << i);
            }
        }
    }

    return result;
        
    }
};