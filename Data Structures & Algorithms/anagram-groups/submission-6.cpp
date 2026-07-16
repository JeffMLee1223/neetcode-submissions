class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);  // map[] will give u access to that value {key, value}

            // int n = mp[key].size();
            // while (n > 0) {
            //     cout << mp[key][n-1] << endl;
            //     n--;
            // }
        }

        unordered_map<string, vector<string>>::iterator it;

        for (it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};
