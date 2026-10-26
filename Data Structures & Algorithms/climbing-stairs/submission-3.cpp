class Solution {
private:
    vector<int> cache;
    int ways(int n){
        if( n <= 2){
            return n;
        }

        if(cache[n] != -1){
            return cache[n];
        }

        cache [n] = ways(n-1) + ways(n-2);

        return cache[n];
    }
public:

    int climbStairs(int n) {
        cache.resize(n+1,-1);
        return ways(n);
    }
};
