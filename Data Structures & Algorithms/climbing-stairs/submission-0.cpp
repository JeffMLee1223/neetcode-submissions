class Solution {
   public:
    map<int, int> memo;

    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        if(memo.count(n)){
            return memo[n];
        }else{
            memo[n] = climbStairs(n-1) + climbStairs(n-2);
            return memo[n];
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};