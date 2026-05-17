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
        ListNode *slow=head,*fast=head,*prev=nullptr;
        while(fast&& fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=nullptr;
        return slow;
    }

    ListNode* merge(ListNode *l1,ListNode*l2){
        ListNode*dummy= new ListNode(-1);
        ListNode *temp=dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                temp->next=new ListNode(l1->val);
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=new ListNode(l2->val);
                temp=temp->next;
                l2=l2->next;
            }
        }
        while(l1){
            temp->next=new ListNode(l1->val);
            temp=temp->next;
            l1=l1->next;
        }
        while(l2){
            temp->next=new ListNode(l2->val);
            temp=temp->next;
            l2=l2->next;
        }
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* &head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* mid=getMid(head);
        ListNode *left=head,*right=mid;
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        head=mergeSort(head);
        return head;
    }
};