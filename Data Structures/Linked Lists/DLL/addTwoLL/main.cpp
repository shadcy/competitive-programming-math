/*
 * Author: Shreyash (shadcy)
 * Created: 2026-07-11
 * Template: LeetCode C++
 *
 * Paste function inside class Solution and run.
 */


//  Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //will start with creating dummy node
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(l1 || l2){
           int sum = carry;
           if(l1) sum+= l1->val;
           if(l2) sum+= l2->val;

           curr->next= new ListNode(sum%10);
           carry = sum/10;

           if(l1) l1 = l1->next;
           if(l2) l2 = l2->next;
           curr = curr->next;
        }
        if(carry){
            curr->next = new ListNode(1);
        }
        return dummyNode->next;
    }
};