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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    // Create a bitset of size 100001 (large enough to cover all potential values in nums)
    bitset<100001> hasN = 0;
    
    // Mark all values in the nums vector as 'true' in the bitset
    for (int x : nums) 
        hasN[x] = 1;

    // Create a dummy node pointing to the head to handle edge cases like removal of the head node
    ListNode dummy(0, head);

    // 'prev' is initialized to point to the dummy node, and 'tmp' is initialized to NULL
    ListNode* prev = &dummy, *tmp = NULL;

    // Traverse through the linked list
    for (ListNode* curr = head; curr; curr = curr->next, delete tmp) {
        // If the current node's value is in the 'nums' vector (i.e., it's marked in the bitset)
        if (hasN[curr->val]) { 
            // Skip the current node by updating the 'next' pointer of the previous node
            prev->next = curr->next;
            // Temporarily store the current node in 'tmp' to delete it after the iteration
            tmp = curr;
        } 
        else {
            // If the value is not in the bitset, move 'prev' forward to the current node
            prev = prev->next;
            // Set 'tmp' to NULL as there's no node to delete
            tmp = NULL;
        }
    }
    
    // Return the new head of the list, which is the node after the dummy node
    return dummy.next;
}

};