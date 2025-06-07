// Time  complexity: O(n)
// Space complexity: O(1)
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
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        // Find middle
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse second half
        ListNode *rev = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = rev;
            rev = slow;
            slow = next;
        }

        // Compare both halves
        ListNode *left = head;
        ListNode *right = rev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
