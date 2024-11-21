// Time  complexity: O(max(l1 , l2))
// Space complexity: O(1)

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
#include <cmath>
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        bool carry = 0;
        // NOTE: A linked list which starts with a node that will be
        // discraded is usually called dummy
        ListNode *dummy = new ListNode();
        ListNode *n = dummy;
        while (l1 || l2) {
            int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0)) + carry;
            carry = sum / 10;

            n->next = new ListNode(sum % 10);
            n = n->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) n->next = new ListNode(1);
        return dummy->next;
    }
};
