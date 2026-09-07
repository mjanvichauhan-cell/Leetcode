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
//METHOD 1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr){
        while(curr->next && curr->val==curr->next->val){
            ListNode* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
            curr=curr->next;
        }
        return head;
    }
};

//METHOD 2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr && curr->next){
            if(curr->val==curr->next->val) curr->next=curr->next->next;
            else curr=curr->next;
        }
        return head;
    }
};