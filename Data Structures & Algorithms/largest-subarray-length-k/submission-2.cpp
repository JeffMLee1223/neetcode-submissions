class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        vector<int> ans;
        int largestIndex = 0;

        for(int i =0; i < nums.size(); i++){
            if( (i+k) > nums.size()){
                break;
            }
            if( nums[i] > nums[largestIndex]){
                largestIndex = i;
            }

        }

        for(int j = largestIndex; j < (largestIndex + k); j++){
            ans.push_back(nums[j]);
        }



        return ans;
    }
};
