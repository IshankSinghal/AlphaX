class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize variables to keep track of the maximum heights from the left and right.
        int lmax = 0, rmax = 0, total = 0;
        // Initialize two pointers, one starting from the left and one from the right.
        int l = 0;
        int r = height.size() - 1;

        // Loop until the two pointers meet.
        while (l < r) {
            // If the height at the left pointer is less than or equal to the height at the right pointer,
            // process the left side.
            if (height[l] <= height[r]) {
                // If the maximum height on the left is greater than the current height,
                // it means water can be trapped, so add the difference to the total.
                if (lmax > height[l]) {
                    total += lmax - height[l];
                }
                // Otherwise, update the maximum height on the left.
                else {
                    lmax = height[l];
                }
                // Move the left pointer to the right.
                l++;
            } 
            // If the height at the right pointer is less than the height at the left pointer,
            // process the right side.
            else {
                // If the maximum height on the right is greater than the current height,
                // it means water can be trapped, so add the difference to the total.
                if (rmax > height[r]) {
                    total += rmax - height[r];
                }
                // Otherwise, update the maximum height on the right.
                else {
                    rmax = height[r];
                }
                // Move the right pointer to the left.
                r--;
            }
        }
        // Return the total amount of trapped water.
        return total;
    }
};
