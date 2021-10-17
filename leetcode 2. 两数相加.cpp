/*
    https://leetcode-cn.com/problems/add-two-numbers
    模拟加法，相关类型：大数加法等
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr , *ans=nullptr;
        int sum = 0;//用于计算和存储进位
        while(l1 || l2){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            sum += a+b;
            if(!res){
                ans = res = new ListNode(sum % 10);
            }
            else{
                res->next = new ListNode(sum % 10);
                res = res->next;
            }
            sum /= 10; //处理进位；
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        //最后一位还有进位
        if(sum){
            res->next = new ListNode(sum);
        }

        return ans;
    }
};