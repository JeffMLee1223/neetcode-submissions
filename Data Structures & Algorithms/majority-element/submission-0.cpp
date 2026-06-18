class Solution {
public:
    int majorityElement(vector<int>& nums) {
        double maj = nums.size() / 2;
        int ans = 0;

        unordered_map<int, vector<int>> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]].push_back(nums[i]); 
        }
        unordered_map<int,vector<int>>::iterator it;

        for(it = freq.begin(); it != freq.end(); it++){
            if((it->second).size() > maj){
                ans = it->first;
            }
        }
        return ans;
    }
};