class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to apply a two-pointer approach
        sort(nums.begin(), nums.end());
        
        // Initialize minDiff to the maximum possible integer value
        // This will hold the closest sum we find
        int minDiff = INT_MAX/2;
        int n = nums.size();

        // Iterate through the array, treating each element as a fixed starting point
        for (int i = 0; i < n; i++) {
            // Set two pointers: one just after the current element and one at the end
            int left = i + 1;
            int right = n - 1;

            // Use the two pointers to explore pairs of elements for a valid sum
            while (left < right) {
                // Calculate the current sum of the three elements
                int sum = nums[i] + nums[left];
                sum += nums[right];

                // If this sum is closer to the target than the previous closest, update minDiff
                if (abs(sum - target) < abs(minDiff - target))
                    minDiff = sum;

                // Move pointers based on the comparison with the target
                if (sum < target)
                    left++;  // Need a larger sum, so move the left pointer to the right
                else if (sum > target)
                    right--; // Need a smaller sum, so move the right pointer to the left
                else
                    return sum; // Exact match found, return the sum
            }
        }

        // Return the closest sum found
        return minDiff;
    }
};
