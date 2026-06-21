class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int left = 0;
        while( left < k){
            int temp = nums[nums.size()-1];
            nums.erase(nums.end()-1);
            nums.insert(nums.begin(),temp);
            left++;
        }
    }
};