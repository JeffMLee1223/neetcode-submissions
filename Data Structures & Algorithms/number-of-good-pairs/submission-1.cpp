class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int>mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int pairs = 0;
        unordered_map<int, int>::iterator it;

        for(it = mp.begin(); it!= mp.end(); it++){
            pairs += (it->second * (it->second-1))/2;
        }

        return pairs;
    }
};