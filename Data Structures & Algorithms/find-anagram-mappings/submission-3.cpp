class Solution {
   public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
