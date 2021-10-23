/*
    leetcode 78. 子集
    https://leetcode-cn.com/problems/subsets/
    位运算进行枚举
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < n ; i++){
            int j = i;
            int index = nums.size()-1;
            vector<int> t;
            while(j>0){
                if(j&1) t.push_back(nums[index]);
                index --;
                j = j >> 1;
            }
            res.push_back(t);
        }

        return res;
    }
};