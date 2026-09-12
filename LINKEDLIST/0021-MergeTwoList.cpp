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
// APPROACH 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* dummyNode=new ListNode(-1);
       ListNode* ptr1=list1;
       ListNode* ptr2=list2;
       ListNode* ptr3=dummyNode;

       while(ptr1 && ptr2){
       if(ptr1->val<ptr2->val){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
       }
       else{
        ptr3->next=ptr2;
        ptr2=ptr2->next;
       }

       ptr3=ptr3->next;

       }

       if(ptr1)  ptr3->next=ptr1;
       else ptr3->next=ptr2;

       return dummyNode->next;
    }
};

//APPROACH 2 using recursion 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;

        if (list2 == nullptr) return list1;
        ListNode* result;
        if (list1->val <= list2->val) {
            result=list1;
            list1->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result=list2;
            list2->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }
};
