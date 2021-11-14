/*
    leetcode 142. 环形链表 II
    https://leetcode-cn.com/problems/linked-list-cycle-ii/
    快慢指针，相遇点很重要，将公式算出来
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head , *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode* res = head;
                while(res != slow){
                    res = res->next;
                    slow = slow->next;
                }
                return res;
            }
        }
        return NULL;
    }
};