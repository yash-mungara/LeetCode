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
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);
        
        // Reverse the current node's pointer
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        bool ans=true;
        ListNode* slow=head, *fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* head1 = head;
        while(head1!=slow->next){
            if(newHead!=nullptr && head1->val!=newHead->val) {ans=false;break;}
            head1 = head1->next;
            if(newHead!=nullptr) newHead=newHead->next;
        }
        return ans;
    }
};
