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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* h1 = head;
        if(head==NULL){
            return NULL;
        }
        ListNode* h2 = head->next;
        ListNode* odd = h1;
        ListNode* even = h2;
        while(odd->next){
            odd->next = even->next;
            if(odd->next==NULL){
                break;
            }
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = h2;
        return h1;
    }
};