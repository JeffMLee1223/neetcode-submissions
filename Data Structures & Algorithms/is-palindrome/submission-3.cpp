class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                // is alphanumeric is to check wether something is
                // a number || alphabatic or not
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;  // to lower is to convert uppercase to lowercase
                // if you insert number, it will still be the same number
            }
            right--;
            left++;
        }
        return true;
    }
    // the idea is that we have to track string from the beginning and from the end at the same time
    // when left is less than right, that means we haven't reach the middle of the string
    // ABCBA  will stop at B (two side will share the middle C)
    // ABCCBA will stop at C
};
