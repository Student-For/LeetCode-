/*
    leetcode 160. 相交链表
    https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
    哈希 双指针
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //双指针写法
 /*
    遍历将近两遍
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* a = headA , *b = headB;
        while(a != b){
            if(a){
                a = a->next;
            }
            else{
                a = headB;
            }
            if(b){
                b = b->next;
            }
            else {
                b = headA;
            }
        }

        return a;
    }
};

/*
    哈希写法
    用哈希存储其中一个链表的所有节点，再遍历另外一个链表；
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> mp;
        ListNode* tmp = headA;
        while(tmp){
            mp.insert(tmp);
            tmp = tmp->next;
        }

        tmp = headB;
        while(tmp){
            if(mp.count(tmp)){
                return tmp;
            }
            tmp = tmp->next;
        }
        return NULL;
    }
};
*/