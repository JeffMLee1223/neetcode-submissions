class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> freq;
        // create an hashtable,first
        // int is key(what number), and second value is value, for how many times

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            freq[key].push_back(nums[i]);
        }

        unordered_map<int, vector<int>>::iterator it;
        vector<vector<int>> bucket(nums.size()+1);
        // create an bucket, index is the frequency
        //  bucket[3] means number that appear three times, in lhs ex1 case,it will be 3

        for (it = freq.begin(); it != freq.end(); it++) {
            bucket[(it->second).size()].push_back(it->first);
            //^^^^bucket[freq] = key
        }

        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (ans.size() == k) {
                break;
            }
            for (int j = 0; j <bucket[i].size() ; j++) {
                ans.push_back(bucket[i][j]);
            }
        }
        return ans;
    }
};