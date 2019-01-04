/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto ___ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode root(0), *runner = &root;
        int carry = 0;
        while(l1 || l2 || carry){
            int v1 = l1 ? l1->val:0;
            int v2 = l2 ? l2->val:0;
            int sum = v1 + v2 + carry;
            runner->next = new ListNode(sum % 10);
            runner = runner->next;
            carry = sum / 10;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return root.next;
    }
};
