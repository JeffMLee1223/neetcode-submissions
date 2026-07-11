class Solution {
   public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++) {
            int key = i;
            mp[key] = nums2[i];
        }
        unordered_map<int, int>::iterator it;

        for (int i = 0; i < nums1.size(); i++) {
            for (it = mp.begin(); it != mp.end(); it++) {
                if (it->second == nums1[i]) {
                    ans.push_back(it->first);
                    break;
                }
            }
        }

        return ans;
    }
};
