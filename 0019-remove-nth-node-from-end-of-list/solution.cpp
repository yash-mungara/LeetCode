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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* curr=head;
        while(curr!=nullptr){
            size++;
            curr=curr->next;
        }
        curr=head;
        ListNode* prev=curr;
        for(int i=0;i<size-n;i++){
            prev=curr;
            curr=curr->next;
        }
        if (n == size) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        prev->next=curr->next;
        delete(curr);   
        return head;
    }
};
