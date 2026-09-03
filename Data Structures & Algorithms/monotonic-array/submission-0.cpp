class Solution {
   public:
    bool isMonotonic(vector<int>& nums) {
        bool found = false;
        bool increasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                increasing = nums[i] > nums[i - 1];
                found = true;
                break;
            }
        }

        if (!found) {
            return true;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1] && increasing) {
                return false;
            }

            if (nums[i] > nums[i - 1] && !increasing) {
                return false;
            }
        }

        return true;
    }
};