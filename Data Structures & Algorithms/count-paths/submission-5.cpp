class Solution { // top down

public:
    int cache[100][100];
    int dfs(int r, int c, int m, int n){
        if(r == m || c == n){
            return 0;
        }

        if(r == m-1 && c == n-1){
            return 1;
        }

        if(cache[r][c] != -1){
            return cache[r][c];
        }

        cache[r][c] = dfs(r+1,c,m,n) + dfs(r,c+1,m,n); 

        return cache[r][c];
    }
    int uniquePaths(int m, int n) {

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                cache[r][c] = -1;
            }
        }
        return dfs(0,0,m,n);
    }
};
