class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i = static_cast<int>(s.size() - 1);
        while (s[i] == ' ' && i >= 0) {
            i--;
        }
        int length = 0;
        while (s[i] != ' ' && i >= 0) {
            length++;
            i--;
        }
        return length;
    }
};