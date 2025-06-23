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
 struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
        ListNode*, vector<ListNode*>, compare
        > pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(auto head:lists){
            if(head)
            pq.push(head);
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            temp->next = it;
            it = it->next;
            if(it)
                pq.push(it);
            temp = temp->next;
        }
        return dummy->next;
    }
};