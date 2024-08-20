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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head;
        while(p!=NULL){
            n++;
            p = p->next;
        }
        int counter = 1;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(counter<k){
            p1 = p1->next;
            counter++;
        }
        counter = 1;
        while(counter<n-k+1){
            p2 = p2->next;
            counter++;
        }
        swap(p1->val,p2->val);
        return head;
    }
};