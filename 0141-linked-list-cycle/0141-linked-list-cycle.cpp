/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mpp;
        ListNode* temp=head;
        while(temp){
            mpp[temp]=1;
            ListNode* next=temp->next;
            if(mpp.find(next)==mpp.end()){
                temp=next;
                continue;
            }
            else return true;
        }
        return false;
    }
};