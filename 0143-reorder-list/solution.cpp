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
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }
        vector<ListNode*> pointers(size);
        curr = head;
        int i=0;
        while(curr){
            pointers[i] = curr;
            curr = curr->next;
            i++;
        }

        int st = 0, end = size-1;
        while(st<end){
            pointers[st]->next = pointers[end];
            pointers[end]->next = pointers[st+1];
            st++;end--;
        }
        pointers[size/2]->next = NULL;
    }
};
