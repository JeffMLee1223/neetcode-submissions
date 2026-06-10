class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int length = 1;
        int result = 1;


        for (int i = 1; i < nums.size(); i++) {
            if(nums[i]==nums[i-1]){// the same with previous number
                continue;
            }
            else if (nums[i] == nums[i-1] + 1){
                length++;
            }else{
                length = 1;
            }
            result = max(result,length);
        }
        return result;
    }
};
