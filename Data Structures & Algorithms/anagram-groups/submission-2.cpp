class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;  // C++ Default #include <unordered_map>
        // mp is hashtable, key is string, value is string vector

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];  // we take string as key.

            sort(key.begin(), key.end());  // sort key, cat act will be the same

            mp[key].push_back(strs[i]);  // the string with same key will be push into same group
        }

        vector<vector<string>> ans;
        unordered_map<string, vector<string>>::iterator it; 
        // it is a pointer that point to single pair of data inside hashtable
        //it->first will be the key, it ->second will be value
                            
        for(it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
            
        }
        return ans;

    }

    // using c++ default hashtable, must follow the order key then value.
};
