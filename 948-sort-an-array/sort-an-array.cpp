// HEAP SORT
class Solution {
public:
    // Heapify function to maintain max-heap property
    void heapify(vector<int>& nums, int size, int i) {
        int largest = i;       // Assume root is the largest
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // Check if left child exists and is greater than root
        if (left < size && nums[left] > nums[largest]) {
            largest = left;
        }
        // Check if right child exists and is greater than the current largest
        if (right < size && nums[right] > nums[largest]) {
            largest = right;
        }

        // If the largest is not the root, swap and continue heapifying
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, size, largest);
        }
    }

    // Function to perform heap sort
    void heapSort(vector<int>& nums, int n) {
        // Step 1: Build Max-Heap
        for (int i = n / 2 - 1; i >= 0;
             i--) { // Start from the last non-leaf node
            heapify(nums, n, i);
        }

        // Step 2: Extract elements one by one from the heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to the end
            swap(nums[0], nums[i]);

            // Call heapify on the reduced heap
            heapify(nums, i, 0);
        }
    }

    // Sort array function
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};
