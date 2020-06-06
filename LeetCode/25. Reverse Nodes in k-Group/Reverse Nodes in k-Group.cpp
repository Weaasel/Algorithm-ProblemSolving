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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        ListNode *root = NULL, *tail = NULL;
        for(int i=0;i<n/k;i++) {
            for(int j=k-1;j>=0;j--) {
                ListNode *tmp = new ListNode(v[i*k + j]);
                if(root == NULL) {
                 root = tmp;
                 tail = tmp;
                }
                else {
                 tail->next = tmp;
                 tail = tmp;
                }
            }
        }
        for(int i=n/k * k;i<n;i++) {
            ListNode *tmp = new ListNode(v[i]);
            if(root == NULL) {
                root = tmp;
                tail = tmp;
            }
            else {
                tail->next = tmp;
                tail = tmp;
            }
        }
        return root;
    }
};
