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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode *temp=head;
        int count=1;
        while(temp->next){
            temp=temp->next;
            count++;
        }
        k=k%count;
        if(k==0) return head;
        temp->next=head;
        int i=1;
        temp=head;
        while(i<count-k){
            temp=temp->next;
            i++;
        }
        head=temp->next;
        temp->next=nullptr;

        return head;
    }
};