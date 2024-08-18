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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize a fast pointer that will move n steps ahead of the head
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast reaches NULL, it means we need to remove the first node
        if (fast == NULL) {
            return head->next; // The head node is removed by returning the second node as the new head
        }

        // Initialize a slow pointer at the head
        ListNode* slow = head;

        // Move both fast and slow pointers until fast reaches the last node
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // The slow pointer is now at the node just before the one we need to remove
        ListNode* delNode = slow->next;    // Node to be deleted
        slow->next = delNode->next;        // Bypass the node to be deleted
        delNode->next = NULL;              // Disconnect the node to be deleted from the list
        delete delNode;                    // Free the memory of the deleted node

        return head; // Return the head of the modified list
    }
};
