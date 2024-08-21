class Solution {
public:
    // Helper function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;  // Previous pointer to keep track of the previous node
        ListNode* curr = head;     // Current pointer to traverse the list
        while (curr != nullptr) {  // Traverse the list until the end
            ListNode* next = curr->next; // Store the next node
            curr->next = prev;    // Reverse the current node's next pointer
            prev = curr;          // Move the prev pointer to the current node
            curr = next;          // Move the curr pointer to the next node
        }
        return prev;              // Return the new head of the reversed list
    }
    
    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;    // Slow pointer to reach the middle of the list
        ListNode* fast = head;    // Fast pointer to reach the end of the list

        // Move slow to the middle of the list and fast to the end
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* rev = reverse(slow);
        
        // Compare the first half and the reversed second half
        while (rev != nullptr) {  // Traverse through the reversed half
            if (head->val != rev->val) {  // If values don't match, it's not a palindrome
                return false;
            }
            head = head->next;  // Move head pointer forward
            rev = rev->next;    // Move rev pointer forward
        }
        return true;  // If all values matched, it's a palindrome
    }
};
