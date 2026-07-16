#include<bits/stdc++.h>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    // ListNode* arrayToLL(vector<int> & arr){
    //     int size = arr.size(); //get the valid size
    //     if(size == 0){
    //         return nullptr;
    //     }
    //     ListNode* head = new ListNode(arr[0]);
    //     ListNode* temp = head;
    //     if(size == 1){
    //         return head;
    //     }
    //     for(int i=1;i<size;i++){
    //         temp->next=new ListNode(arr[i]);
    //         temp=temp->next;
    //     }
    //     return head;
    // }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     //using the brute force solution to solve this problem first and then move to
    //     //the more optimal solution

    //     /*
    //     Method 1: of doing so is having a final array store all the linked lists to the array
    //     and then sort that vector or array. and start creating a ll from the array
    //     */
    //     vector<int>tmp;
    //     long long size = lists.size();
    //     for(int i=0;i<size;i++){
    //         ListNode* temp = lists[i];
    //         while(temp!=nullptr){
    //             tmp.push_back(temp->val);
    //             temp=temp->next;
    //         }
    //     }

    //     sort(tmp.begin(), tmp.end());
        
    //     ListNode* res = arrayToLL(tmp);
    //     return res;

    // }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1)
        temp->next=list1;
        if(list2)
        temp->next=list2;
        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        Method 2: Method 2 is using the merge2list of the previous problems, i have just solved today
        */
        //Lets handle the base cases first
        int size = lists.size();
        if(size==0){
            return nullptr;
        }
        //Incase there is only one ll, then we'll return as is
        if(size==1){
            return lists[0];
        }
        //Game starts here, now we have the cases where we have >=2 lists
        ListNode* res = mergeTwoLists(lists[0], lists[1]);
        for(int i=2; i<size;  i++){
            //incase we have 2 elements this loop wont run, will do for >=3
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};

int main(){
    //too lazy to add the things to run on pc, sorry
    //hope future me understands
}