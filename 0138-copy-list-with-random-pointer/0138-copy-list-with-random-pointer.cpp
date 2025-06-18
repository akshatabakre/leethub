/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return NULL;
        map<Node*,Node*> hash;
        hash[NULL] = NULL;
        Node* temp = head;
        Node* newhead = NULL;
        while(temp){
            Node* newnode = new Node(temp->val);
            if(temp==head){
                newhead = newnode;
            }
            hash[temp] = newnode;
            temp = temp->next;
        }
        temp = head;
        Node* res = NULL;
        while(temp){
            res = hash[temp];
            res->next = hash[temp->next];
            res->random = hash[temp->random];
            temp = temp->next;
        }
        return newhead;
    }
};