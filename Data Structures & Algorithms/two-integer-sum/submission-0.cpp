class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1, index2;

        for(int i =0; i < nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++ ){
                if(target - nums[i] == nums[j]){
                    index1 = i;
                    index2 = j;
                }
            }
        }
        return {index1,index2};
    }

};
