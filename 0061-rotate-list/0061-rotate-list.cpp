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
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *slow=head,*fast=head;
        int len=0;
        while(slow){
            len++;
            slow=slow->next;
        }
        slow=head;
        k=k%len;
        while(k--)
            fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};