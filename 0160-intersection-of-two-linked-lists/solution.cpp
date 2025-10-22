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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1=headA, *curr2=headB;
        int m=0,n=0;
        while(curr1!=nullptr){
            m++;
            curr1=curr1->next;
        }
        curr1=headA;
        while(curr2!=nullptr){
            n++;
            curr2=curr2->next;
        }
        curr2=headB;
        if(m>n){
            for(int i=0;i<m-n;i++){
                curr1=curr1->next;
            }
        } else{
            for(int i=0;i<n-m;i++){
                curr2=curr2->next;
            }
        }
        while(curr1!=nullptr){
            if(curr1==curr2) break;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;
    }
};
