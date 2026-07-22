class Solution {
   public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strings.size(); i++) {
            string key = "";
            for (int j = 1; j < strings[i].size(); j++) {  // for word that has more than one char
                int diff = 0;
                diff = (strings[i][j] - strings[i][j - 1] + 26) % 26;
                key += to_string(diff) + "#";
            }
            mp[key].push_back(strings[i]);
        }
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>::iterator it;

        for (it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};
