class Solution {
   public:
    bool canPermutePalindrome(string s) {
        int count[128] = {0};

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }
        int oddCount = 0;
        for (int i = 0; i < 128 && oddCount <= 1; i++) {
            if (count[i] % 2) {
                oddCount += 1;
            }
        }

        return oddCount <= 1;
    }
};
