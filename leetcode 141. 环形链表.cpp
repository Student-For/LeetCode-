/*
    leetcode 141. 环形链表
    https://leetcode-cn.com/problems/linked-list-cycle/
    哈希，快慢指针
    快慢指针，如果快指针会和慢指针重合，一定是有环的
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head , *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

/*
哈希写法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode* > us;
        ListNode* tmp = head;
        while(tmp){
            if(us.count(tmp)) return true;
            us.insert(tmp);
            tmp = tmp->next;
        } 
        return false;
    }
};
*/