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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto l:lists) {
            while(l!=NULL) {
                v.push_back(l->val);
                l = l->next;
            }
        }
        sort(v.begin(), v.end());
        ListNode* root = NULL;
        ListNode* tail = NULL;
        for(int val:v) {
            ListNode* tmp = new ListNode(val);
            if(root==NULL) {
                root = tmp;
                tail = tmp;
                continue;
            }
            tail->next = tmp;
            tail = tmp;
        }
        return root;
    }
};
