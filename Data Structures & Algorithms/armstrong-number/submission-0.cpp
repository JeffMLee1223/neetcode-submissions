class Solution {
   public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = to_string(n).size();
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += pow(digit, digits);
            n /= 10;
        }

        return sum == original;
    }
};
