/*
    https://leetcode-cn.com/problems/container-with-most-water/
    解法：双指针
    思路：思考一下所有能出现最大容量的容器
        1.两个垂直线的间隔长
        2.垂直线长
        所以我们可以用双指针从两端开始遍历
        随后移动两个值中小的那个值（因为如果移动值大的，垂直线的最小长度不会变，但是间隔变小了）
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0 ,j = n-1;
        int maxx = 0;
        while(i < j){
            if(height[i] <= height[j]){
                maxx = max(maxx,height[i]*(j-i));
                i++;
            }
            else{
                maxx = max(maxx,height[j]*(j-i));
                j--;
            }

        }

        return maxx;
    }
};