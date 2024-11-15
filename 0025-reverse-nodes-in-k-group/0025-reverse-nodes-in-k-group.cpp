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
        if (!head || k == 1) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;
        ListNode *curr = head;

        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        while (length >= k) {
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *groupEnd = groupStart;
            for (int i = 0; i < k - 1; i++) {
                groupEnd = groupEnd->next;
            }
            ListNode *nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;
            prevGroupEnd->next = reverseList(groupStart);

            groupStart->next = nextGroupStart;
            prevGroupEnd = groupStart;
            length -= k;
        }

        return dummy->next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

