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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr = new ListNode(0);
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* p = ptr;
        while(p1!=NULL && p2!=NULL){
            ListNode* newnode = new ListNode;
            if(p1->val <= p2->val){
                newnode->val = p1->val;
                p->next = newnode;
                p = newnode;
                p1 = p1->next;
            } else {
                newnode->val = p2->val;
                p->next = newnode;
                p = newnode;
                p2 = p2->next;
            }
        }
        while(p1!=NULL){
            ListNode* newnode = new ListNode;
            newnode->val = p1->val;
            p->next = newnode;
            p = newnode;
            p1 = p1->next;
        }
        while(p2!=NULL){
            ListNode* newnode = new ListNode;
            newnode->val = p2->val;
            p->next = newnode;
            p = newnode;
            p2 = p2->next;
        }
        return ptr->next;
    }
};