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
    int getDecimalValue(ListNode* head) {
        int d = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            d = ((d<<1)|(ptr->val));
            ptr = ptr->next;
        }
        return d;
    }
};