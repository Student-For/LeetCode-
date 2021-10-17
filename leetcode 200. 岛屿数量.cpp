/*
    leetcode 200. 岛屿数量
    https://leetcode-cn.com/problems/number-of-islands/
    一道 dfs
*/

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    res ++;
                    dfs(grid,i,j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& g ,int r ,int c){
        int n = g.size();
        int m = g[0].size();

        g[r][c] = '0';

        //处理边界，并搜索
        if(r-1 >= 0 && g[r-1][c] == '1') dfs(g,r-1,c);
        if(r+1 < n && g[r+1][c] == '1') dfs(g,r+1,c);
        if(c-1 >= 0 && g[r][c-1] == '1' ) dfs(g,r,c-1);
        if(c+1 < m && g[r][c+1] == '1' ) dfs(g,r,c+1);   
    }
};