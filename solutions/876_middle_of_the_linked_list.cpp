// Time  complexity: O(n)
// Space complexity: O(1)
// NOTE: https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Initial Solution
// class Solution {
//   public:
//     ListNode *middleNode(ListNode *head) {
//         ListNode *ptr = head;
//         ListNode *mid = head;
//
//         if (!ptr) {
//             return nullptr;
//         }
//
//         int len = 1;
//         int mididx = 0;
//         while (ptr) {
//             ptr = ptr->next;
//             int new_mididx = len / 2 - 1;
//             for (int i = mididx; i < new_mididx; ++i) {
//                 mid = mid->next;
//             }
//             mididx = new_mididx;
//             len++;
//         }
//
//         return mid;
//     }
// };
