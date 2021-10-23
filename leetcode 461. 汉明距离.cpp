/*
    leetcode 461. 汉明距离
    https://leetcode-cn.com/problems/hamming-distance/
    简单题，位元算
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        //if(x < y) return hammingDistance(y,x);
        int res =0;
        while(x > 0 || y > 0){
            if((x&1) != (y&1)) res++;
            if(x) x >>= 1;
            if(y) y >>= 1;
        }
        return res;
    }
};