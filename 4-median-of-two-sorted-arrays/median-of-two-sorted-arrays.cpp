class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of the input arrays
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Total size of the merged array
        int n = n1 + n2;
        // Indices where the median elements would be located
        int i1 = n / 2;     // Middle index for odd length or the right middle for even length
        int i2 = i1 - 1;    // Left middle index for even length

        // Pointers to iterate over nums1 and nums2
        int i = 0;
        int j = 0;

        // Counter for the merged array index
        int cnt = 0;
        // Variables to store the elements at median positions
        int ind1El = -1;
        int ind2El = -1;

        // Merge nums1 and nums2, tracking the elements at median positions
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == i1) ind1El = nums1[i];  // Store the element at index i1
                if (cnt == i2) ind2El = nums1[i];  // Store the element at index i2 (for even total length)
                cnt++;  // Increment the merged array index counter
                i++;    // Move to the next element in nums1
            } else {
                if (cnt == i1) ind1El = nums2[j];  // Store the element at index i1
                if (cnt == i2) ind2El = nums2[j];  // Store the element at index i2 (for even total length)
                cnt++;  // Increment the merged array index counter
                j++;    // Move to the next element in nums2
            }
        }

        // If there are remaining elements in nums1
        while (i < n1) {
            if (cnt == i1) ind1El = nums1[i];  // Store the element at index i1
            if (cnt == i2) ind2El = nums1[i];  // Store the element at index i2 (for even total length)
            cnt++;  // Increment the merged array index counter
            i++;    // Move to the next element in nums1
        }

        // If there are remaining elements in nums2
        while (j < n2) {
            if (cnt == i1) ind1El = nums2[j];  // Store the element at index i1
            if (cnt == i2) ind2El = nums2[j];  // Store the element at index i2 (for even total length)
            cnt++;  // Increment the merged array index counter
            j++;    // Move to the next element in nums2
        }

        // If the total number of elements is even, the median is the average of the two middle elements
        if (n % 2 == 0) {
            return (double)((double)(ind1El + ind2El)) / 2.0;
        }
        // If the total number of elements is odd, the median is the middle element
        return ind1El;
    }
};
