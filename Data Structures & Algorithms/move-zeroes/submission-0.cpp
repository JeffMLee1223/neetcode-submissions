class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            if(nums[left] == 0){
                nums.push_back(0);
                nums.erase(nums.begin()+left);
                right--;
            }else{
                left++;
            }
            

        }
    }
};