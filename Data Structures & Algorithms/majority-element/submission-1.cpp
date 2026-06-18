class Solution {
public:
    int majorityElement(vector<int>& nums) {
        double maj = nums.size() / 2;
        int ans = 0;

        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;

        for(it = freq.begin(); it != freq.end(); it++){
            if((it->second) > maj){
                ans = it->first;
            }
        }
        return ans;
    }
};;