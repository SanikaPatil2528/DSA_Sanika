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
private:
    ListNode* getKthNode(ListNode*node,int k){
        ListNode*temp=node;
        while(--k){
            temp=temp->next;
            if(temp==nullptr) return nullptr;
        }
        return temp;
    }
    void reverseLL(ListNode*&head){
        if(head==nullptr || head->next==nullptr) return;
        ListNode*temp=head,*prev=nullptr,*nextNode=head->next;
        while(temp && nextNode){
            temp->next=prev;
            prev=temp;
            temp=nextNode;
            nextNode=nextNode->next;
        }
        temp->next=prev;
        head=temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode *prev=nullptr;
        while(temp!=nullptr){
            ListNode* kth=getKthNode(temp,k);
            if(!kth){
                if(prev) prev->next=temp;
                break;
            }
            else{
                ListNode* nextNode=kth->next;
                kth->next=nullptr;
                ListNode* oldTemp=temp;
                reverseLL(temp);
                if(oldTemp==head){
                    head=kth;
                }
                else{
                    prev->next=kth;
                }
                prev=oldTemp;
                temp=nextNode;
            }
        }
        return head;
    }
};