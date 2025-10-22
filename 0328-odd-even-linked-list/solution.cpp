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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* curr=head, *nex=curr->next, *even=head->next, *previous=curr;
        while(nex!=nullptr){
            curr->next=curr->next->next;
            previous = curr;
            curr=curr->next;
            if(curr!=nullptr) nex->next=curr->next;
            nex=nex->next;
        }
        if(curr==nullptr){//even//
            previous->next=even;
        }
        else{//odd
            curr->next=even;
        }
        return head;
    }
};
