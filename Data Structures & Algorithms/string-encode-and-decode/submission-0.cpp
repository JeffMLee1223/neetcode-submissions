class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (int i = 0; i < strs.size(); i++) {
            encoded_string += to_string(strs[i].size()) + "{" + strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int j = 0;

        while (i < s.size()) {
            j = i;
            while (s[j] != '{') {
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            int start = j + 1;

            string word = s.substr(start, len);
            ans.push_back(word);
            i = start + len;
        }

        return ans;
    }
};
