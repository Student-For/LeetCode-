/*
    leetcode 206. 反转链表
    https://leetcode-cn.com/problems/reverse-linked-list/
    遍历链表然后翻转
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* ne = new ListNode();
            ne = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ne;
        }
        return prev;
    }
};