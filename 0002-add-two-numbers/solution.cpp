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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1=l1, *c2=l2;
        int m=0, n=0;
        while(c1!=nullptr){
            m++;c1=c1->next;
        }
        while(c2!=nullptr){
            n++;c2=c2->next;
        }
        c1=l1;c2=l2;

        if(m>n){
            while(c2!=nullptr){
                c1->val += c2->val;
                if(c1->val>9){
                    c1->val = c1->val%10;
                    if(c1->next!=nullptr) c1->next->val++;
                    else c1->next = new ListNode(1);
                }
                c1=c1->next; c2=c2->next;
            }
            while(c1!=nullptr){
                if(c1->val>9){
                    c1->val = c1->val%10;
                    if(c1->next!=nullptr) c1->next->val++;
                    else c1->next = new ListNode(1);
                }
                c1 = c1->next;
            }
            return l1;
        } else{
            while(c1!=nullptr){
                c2->val += c1->val;
                if(c2->val>9){
                    c2->val = c2->val%10;
                    if(c2->next!=nullptr) c2->next->val++;
                    else c2->next = new ListNode(1);
                }
                c1=c1->next; c2=c2->next;
            }
            while(c2!=nullptr){
                if(c2->val>9){
                    c2->val = c2->val%10;
                    if(c2->next!=nullptr) c2->next->val++;
                    else c2->next = new ListNode(1);
                }
                c2 = c2->next;
            }
            return l2;
        }
        return nullptr;
    }
};
