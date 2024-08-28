class Solution {
public:
    
    // Helper function to perform binary search
    int binarySearch(vector<int>& nums, int low, int high, int x) {
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Calculate the mid-point to avoid overflow
            
            if (nums[mid] == x) return mid;  // If the target is found, return its index
            else if (nums[mid] < x) low = mid + 1;  // If the target is greater, search in the right half
            else high = mid - 1;  // If the target is smaller, search in the left half
        }
        return -1;  // Return -1 if the target is not found
    }

    // Function to find the pivot (the smallest element's index) in a rotated sorted array
    int getPivot(vector<int>& nums, int n) {
        int low = 0;
        int high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;  // Calculate the mid-point

            // If the middle element is greater than the first element,
            // the smallest element must be in the right half
            if (nums[mid] >= nums[0]) low = mid + 1;
            // Otherwise, the smallest element is in the left half
            else high = mid;
        }
        return low;  // 'low' will eventually point to the pivot (smallest element)
    }

    // Main function to search for a target in a rotated sorted array
    int search(vector<int>& nums, int target) {

        int n = nums.size() - 1;  // Get the last index
        int pivot = getPivot(nums, n);  // Find the pivot (smallest element's index)

        // Determine which half of the array to search in
        if (target >= nums[pivot] && target <= nums[n]) {
            // If the target is within the range of the right half
            return binarySearch(nums, pivot, n, target);
        } else {
            // Otherwise, search in the left half
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
