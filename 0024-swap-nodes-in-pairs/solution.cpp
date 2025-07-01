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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        if(temp == NULL || temp->next == NULL){return head;}
        temp = temp->next->next;
        
        
        
        ListNode* prev = swapPairs(temp);

        temp = head;
        ListNode* ans = temp->next;
        ans->next = temp;
        temp->next = prev;

        return ans;
    }

};
