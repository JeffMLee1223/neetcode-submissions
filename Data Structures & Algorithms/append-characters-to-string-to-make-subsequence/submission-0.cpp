class Solution {
   public:
    int appendCharacters(string s, string t) {
        int i = 0;  // s
        int j = 0;  // t

        while (i < s.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return t.size() - j;
    }
};