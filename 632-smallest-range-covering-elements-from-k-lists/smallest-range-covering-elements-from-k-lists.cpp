class node {
public:
    int data; // Value of the element
    int row;  // Row index in the 2D array
    int col;  // Column index in the row

    // Constructor to initialize a node with data, row, and col
    node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Custom comparator for the priority queue (min-heap)
class compare {
public:
    bool operator()(node* a, node* b) { 
        return (a->data > b->data); // Min-heap: smallest value gets highest priority
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(); // Number of rows in the 2D array

        int mini = INT_MAX, maxi = INT_MIN; // Track the smallest and largest elements
        priority_queue<node*, vector<node*>, compare> pq; // Min-heap to store nodes

        // Step 1: Insert the first element of each row into the priority queue
        for (int i = 0; i < n; i++) {
            int elem = nums[i][0]; // First element of the current row
            maxi = max(elem, maxi); // Update the maximum value
            mini = min(elem, mini); // Update the minimum value

            // Push the node containing the element, its row, and column indices
            pq.push(new node(elem, i, 0));
        }

        // Initialize the smallest range with the initial min and max
        int start = mini, end = maxi;

        // Step 2: Process the elements in the priority queue
        while (!pq.empty()) {
            node* topNode = pq.top(); // Get the smallest element
            pq.pop(); // Remove the smallest element

            mini = topNode->data; // Update the current minimum value

            // Check if the current range [mini, maxi] is smaller than the previous range
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi; // Update the smallest range
            }

            // Step 3: Move to the next element in the same row
            if (topNode->col + 1 < nums[topNode->row].size()) {
                // Get the next element in the current row
                int nextElem = nums[topNode->row][topNode->col + 1];

                // Update the maximum value
                maxi = max(maxi, nextElem);

                // Push the next element into the priority queue
                pq.push(new node(nextElem, topNode->row, topNode->col + 1));
            } else {
                // If the current row is exhausted, stop the process
                break;
            }
        }

        // Return the smallest range [start, end]
        return {start, end};
    }
};
