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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        int carry=0,data;
        ListNode *head=nullptr,*tail=nullptr;
        while(temp1 && temp2)
        {
            data=temp1->val+temp2->val+carry;
            carry=data/10;
            data=data%10;
            if(head==nullptr)
            {
                head=new ListNode();
                head->val=data;
                tail=head;
            }
            else
            {
                tail->next=new ListNode();
                tail->next->val=data;
                tail=tail->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
       
        ListNode *curr;
        curr=temp1?temp1:temp2;
        while(curr)
        {
            data=curr->val+carry;
            carry=data/10;
            data=data%10;
            tail->next=new ListNode();
            tail->next->val=data;
            tail=tail->next;
            curr=curr->next;
        }
         if(carry!=0 && curr==nullptr)
        {
            tail->next=new ListNode();
            tail->next->val=carry;
            tail=tail->next;
        }
        return head;
    }
};