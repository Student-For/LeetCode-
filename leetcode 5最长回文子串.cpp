/*
    leetcode 5. 最长回文子串(https://leetcode-cn.com/problems/longest-palindromic-substring/)
    给你一个字符串 s，找到 s 中最长的回文子串。
    示例 1：
        输入：s = "babad"
        输出："bab"
        解释："aba" 同样是符合题意的答案。
*/
/*
    动态规划
    定义状态f(i,j) 为s[j..i]是否为一个回文字符串
    对于每个字符串：
        1.如果字符串长度小于2一定是回文字符串
        2.对于长度大于等于2的字符串
            （1）如果两端的字符不相等一定不是回文字符串
            （2）如果两端字符相等
                长度<=3的一定是回文
                长度>3的由去掉两端字符的字符串决定即s[(j+1).....(i-1)]
*/
class Solution {
public:
        int n = s.size();
        //一个字符肯定是回文
        if(n < 2 ){
            return s;
        }

        //f(i,j)从s[j...i]是不是回文字符串
        vector<vector<bool>> f(n,vector<bool>(n,false));
        int start = 0, maxLen = 1;//最长回文字符串从第几个字符开始，长度是多少

        for(int i = 0 ; i < n ; i++){
            f[i][i] = true;
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                int len = i - j + 1;
                //s[i] != s[j] 肯定不是回文
                if(s[i] != s[j]){
                    f[i][j] = false;
                }
                else{
                    //如果长度小于等于3，如果两端的字符相等则一定是回文字符串
                    if(len <= 3){
                        f[i][j] = true;
                    }
                    else{
                        //由字符串s[j+1...i-1]决定
                        f[i][j] = f[i-1][j+1];
                    }
                }


                //计算长度
                if(f[i][j] && len >= maxLen){
                    maxLen = len;
                    start = j;
                }
            }

        }
        return s.substr(start,maxLen);        
    }
};