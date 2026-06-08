class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            pre[i] = product;
        }

        product = 1;

        for (int i = 0; i < nums.size(); i++) {
            int indexToPush = nums.size() - 1 - i;
            product *= nums[indexToPush];
            suf[indexToPush] = product;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans[i] = suf[1];
            } else if (i == ans.size() - 1 ) {
                ans[i] = pre[ans.size() - 2];
            } else {
                ans[i] = (pre[i - 1] * suf[i + 1]);
            }
        }

        return ans;
    }
};
