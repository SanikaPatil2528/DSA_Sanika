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
    ListNode* getMid(ListNode* &head){
        ListNode *prev=NULL,*slow=head,*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        return slow;
    }
    ListNode* merge(ListNode*left,ListNode*right){
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        ListNode *temp1=left,*temp2=right;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                curr->next=temp1;
                temp1=temp1->next;
                curr=curr->next;
            }
            else{
                curr->next=temp2;
                temp2=temp2->next;
                curr=curr->next;
            }
        }
        while(temp1){
            curr->next=temp1;
            temp1=temp1->next;
            curr=curr->next;
        }
        while(temp2){
            curr->next=temp2;
            temp2=temp2->next;
            curr=curr->next;
        }
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *mid=getMid(head);
        ListNode *left=mergeSort(head);
        ListNode *right=mergeSort(mid);
        return merge(left,right); 
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        head=mergeSort(head);
        return head;
    }
};