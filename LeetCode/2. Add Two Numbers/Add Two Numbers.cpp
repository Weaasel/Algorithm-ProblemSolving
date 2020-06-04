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
        ListNode* root = NULL;
        ListNode* tail = NULL;
        int rem = 0;
        while(l1!=NULL || l2!=NULL) {
            int a1 = 0, a2 = 0;
            if(l1!=NULL) a1 = l1->val;
            if(l2!=NULL) a2 = l2->val;
            int sum = a1 + a2 + rem;
            rem = 0;
            if(sum>=10) rem = 1;
            sum %= 10;
            ListNode* tmp = new ListNode(sum);
            if(root==NULL) {
                root = tmp;
                tail = tmp;
            }
            else {   
                tail->next = tmp;
                tail = tmp;
            }
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(rem==1) {
            ListNode* tmp = new ListNode(1);
            tail->next = tmp;
            tail = tmp;
        }
        return root;
    }
};
