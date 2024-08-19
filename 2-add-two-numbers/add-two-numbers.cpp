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
        // Create a dummy head to simplify the process of adding new nodes
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        // Traverse both linked lists until both are fully processed
        while (t1 || t2) {
            int sum = carry; // Start with the carry from the previous addition

            // Add the value from the first list if available
            if (t1) sum += t1->val;
            // Add the value from the second list if available
            if (t2) sum += t2->val;

            // Create a new node with the digit resulting from the sum modulo 10
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10; // Calculate the carry for the next iteration

            // Link the new node to the current node
            curr->next = newNode;
            curr = curr->next;

            // Move to the next nodes in the lists, if available
            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        // If there's any remaining carry, add a new node for it
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        // Return the next node of dummyHead, which is the actual start of the result list
        return dummyHead->next;
    }
};
