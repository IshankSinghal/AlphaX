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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases: If either list is empty, return the other list
        if (!list1) return list2;
        if (!list2) return list1;

        // Ensure that list1 starts with the smaller value. If not, swap the lists
        if (list1->val > list2->val) swap(list1, list2);

        // 'res' will point to the head of the merged list
        ListNode* res = list1;

        // Traverse both lists until one of them becomes null
        while (list1 && list2) {
            // 'temp' keeps track of the last node in list1 before we switch to list2
            ListNode* temp = list1;

            // Move list1 forward until its current value is greater than list2's current value
            while (list1 && list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }

            // Link the current node of list2 to the last node in list1
            temp->next = list2;

            // Swap list1 and list2 to continue merging in a similar manner
            swap(list1, list2);
        }

        // Return the head of the merged list
        return res;
    }
};
