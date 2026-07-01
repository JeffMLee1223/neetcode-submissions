class Solution {
public:
    void sortColors(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){
            int smallestIndex = i;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] < nums[smallestIndex]){
                    smallestIndex = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[smallestIndex];
            nums[smallestIndex] = temp;
        }
        
    }
};