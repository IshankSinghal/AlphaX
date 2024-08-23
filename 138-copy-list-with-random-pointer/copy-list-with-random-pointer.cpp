/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Create a mapping from original nodes to their corresponding copies.
        unordered_map<Node*, Node*> nodeMap;

        Node* temp = head;

        // First pass: Create a copy of each node and store them in the map.
        while (temp) {
            nodeMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Reset temp to the head of the original list.
        temp = head;

        // Second pass: Set the next and random pointers for the copied nodes.
        while (temp) {
            nodeMap[temp]->next = nodeMap[temp->next];
            nodeMap[temp]->random = nodeMap[temp->random];
            temp = temp->next;
        }

        // Return the head of the copied linked list.
        return nodeMap[head];
    }
};
