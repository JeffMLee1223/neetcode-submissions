class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        // i for iterate and k for next available space

        int k = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                // k is the available space now, what we need to check is if this space are the same
                // with two previous elements(since it's sorted) we won't use i-2 because the
                // original array is changed already.

                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};