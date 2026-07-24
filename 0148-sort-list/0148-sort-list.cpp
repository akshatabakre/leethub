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

    ListNode* merge(ListNode* left,ListNode* right){
        auto dummy = new ListNode(-1);

        auto temp = dummy;
        while(left && right){
            if(left->val < right->val){
                auto newnode = new ListNode(left->val);
                temp->next = newnode;
                temp = newnode;
                left = left->next;
            }else{
                auto newnode = new ListNode(right->val);
                temp->next = newnode;
                temp = newnode;
                right = right->next;
            }
        }


        while(left){
            auto newnode = new ListNode(left->val);
            temp->next = newnode;
            temp = newnode;
            left = left->next;
        }

        while(right){
            auto newnode = new ListNode(right->val);
            temp->next = newnode;
            temp = newnode;
            right = right->next;
        }

        return dummy->next;
    }

    ListNode* middle(ListNode* head){
        auto mid = head;
        auto temp = head;
        while(temp && temp->next){
            temp = temp->next->next;
            if(temp)
                mid = mid->next;
        }
        return mid;
    }

    ListNode* mergesort(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        auto mid = middle(head);
        auto right = mid->next;
        mid->next = NULL;
        auto left = head;

        left = mergesort(left);
        right = mergesort(right);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};