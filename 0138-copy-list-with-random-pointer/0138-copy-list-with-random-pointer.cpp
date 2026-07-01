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
        if(!head) return head;
        Node *curr=head;
        while(curr){
            Node *temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;
        }
        curr=head;
        while(curr && curr->next){
            if(curr->random==NULL) curr->next->random=NULL;
            else curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        Node *copyHead=head->next;
        head->next=copyHead->next;
        curr=copyHead;
        while(curr && curr->next){
            Node *n=curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            n->next=curr->next;
        }
        return copyHead;
    }
};