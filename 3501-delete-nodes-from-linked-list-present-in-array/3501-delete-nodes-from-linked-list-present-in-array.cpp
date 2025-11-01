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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        ListNode* newhead = new ListNode();
        ListNode* p = head;
        ListNode* q = newhead;
        while(p){
            if(s.count(p->val)){
                p = p->next;
            }else{
                q->next = new ListNode(p->val);
                q = q->next;
                p = p->next;
            }
        }
        return newhead->next;
    }
};