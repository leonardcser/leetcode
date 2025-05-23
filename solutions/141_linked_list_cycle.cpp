// Time  complexity: O(n)
// Space complexity: O(1)
// NOTE: https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare
#include <cstddef>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare = head;

        while (tortoise && hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (tortoise == hare) {
                return true;
            }
        }

        return false;
    }
};
