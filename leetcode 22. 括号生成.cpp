/*  
    leetcode 22. 括号生成
    https://leetcode-cn.com/problems/generate-parentheses/
    中等题 递归解决
    如果左右括号相等，那么就只能先放左括号
    如果左<右就可以左右都行
*/
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs("",n,n);
        return res;
    }

    void dfs(string str,int left,int right){
        if(left == 0 && right == 0){
            res.push_back(str);
            return ;
        }
        if(left == right){
            dfs(str+"(",left-1,right);
        }
        else if(left < right){
            if(left > 0){
                 dfs(str+"(",left-1,right);
            }
            dfs(str+")",left,right-1);
        }
    }
};