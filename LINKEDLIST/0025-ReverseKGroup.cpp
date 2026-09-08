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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        int cnt=0;
        
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }

        if(cnt < k) {
            return head;
        }

        cnt=0;
        while(currptr!=NULL && cnt<k){
            ListNode* nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            cnt++;
        }
        
        ListNode* newHead=reverseKGroup(currptr,k);
        head->next=newHead;

        return prevptr;
    }
};