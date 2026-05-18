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
        Node*temp=head;
        while(temp){
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }
        temp=head;
        while(temp){
            if(temp->random==nullptr) temp->next->random=nullptr;
            else temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node *dummy=new Node(-1);
        temp=head;
        Node *res=dummy;
        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};