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
    int pairSum(ListNode* head) {
        int maxi=-1e9;
        int cnt=0;
        ListNode* first=head;
        ListNode* second=head;
        while(second){
            cnt++;
            second=second->next;
        }
        cnt=cnt/2-1;
        second=head;
        while(cnt--)
            second=second->next;
        
        // reverse second half of list
        if(second->next && second->next->next){
            ListNode *prev=second->next,*curr=prev->next,*nex=curr->next;
            while(nex){
                curr->next=prev;
                prev=curr;
                curr=nex;
                nex=nex->next;
            }
            curr->next=prev;
            second->next->next=NULL;
            second->next=curr;
        }

        second=second->next;
        while(second){
            maxi=max(maxi,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return maxi;
    }
};