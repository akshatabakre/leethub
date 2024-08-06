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
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ptr = new ListNode(-1);//return ptr->next
        ListNode* p = ptr;
        int carry = 0;
        while(p1!=NULL && p2!=NULL){
            ListNode* n = new ListNode;
            int sum = p1->val + p2->val + carry;
            carry = sum/10;
            n->val = sum%10;
            p->next = n;
            p = n;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1!=NULL){
            ListNode* n = new ListNode;
            int sum = p1->val + carry;
            carry = sum/10;
            n->val = sum%10;
            p->next = n;
            p = n;
            p1 = p1->next;
        }
        while(p2!=NULL){
            ListNode* n = new ListNode;
            int sum = p2->val + carry;
            carry = sum/10;
            n->val = sum%10;
            p->next = n;
            p = n;
            p2 = p2->next;
        }
        if(carry!=0){
            ListNode* n = new ListNode;
            n->val = carry;
            p->next = n;
        }
        return ptr->next;
    }
};