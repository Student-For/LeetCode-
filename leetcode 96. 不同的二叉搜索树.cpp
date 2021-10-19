/*
    leetcode 96. 不同的二叉搜索树
    https://leetcode-cn.com/problems/unique-binary-search-trees/
    动态规划+数学
    枚举每一个点作为根节点，根节点左侧的作为左子树，右侧的作为右子树
    卡特兰数
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= i ; j++){
                f[i] += f[j-1]*f[i-j];
            }
        }

        return f[n];
    }
};