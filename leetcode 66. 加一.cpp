/*
    leetcode 66. 加一
    简单题
    模拟加法
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int x=0,n = digits.size();
        for(int i = n-1 ; i >= 0 ; i--){
            if(i == n-1) x += digits[i]+1;
            else x += digits[i];
            res.push_back(x%10);
            x /= 10;
        }
        if(x) res.push_back(x);
        reverse(res.begin(),res.end());
        return res;
    }
};