class Solution {
   public:
    bool isPalindorme(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int right = s.size() - 1;
        int left = 0;
        if (s.size() == 1) {
            return true;
        }

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            if (s[left] != s[right]) {
                return isPalindorme(s, left, right - 1) || isPalindorme(s, left + 1, right);
            }
            
        }
        return true;
    }
};
