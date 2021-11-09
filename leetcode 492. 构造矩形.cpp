/*
    leetcode 492. 构造矩形
    https://leetcode-cn.com/problems/construct-the-rectangle/
    简单题
    先取平方根，再找到离平方根最近的可以被整除的数
*/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while(area % w){
            w --;
        }
        vector<int> res;
        res.push_back(area/w);
        res.push_back(w);
        return res;
    }
};