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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* curr = head;
        int count =0;
        while(curr!=nullptr){
            curr=curr->next;
            count++;
        }
        curr=head;
        k=k%count;

        if(k==count || k==0) return head;
        ListNode* prev;
        for(int i=0;i<count-k;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=nullptr;
        ListNode* newhead = curr;
        while(curr!=nullptr && curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next = head;
        return newhead;
    }
};
