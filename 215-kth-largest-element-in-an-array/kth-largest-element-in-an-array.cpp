class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        // Push the first k elements of the array into the heap
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        
        // Iterate through the rest of the array
        for (int i = k; i < nums.size(); i++) {
            // If the current element is larger than the smallest in the heap
            if (pq.top() < nums[i]) {
                // Remove the smallest element
                pq.pop();
                // Insert the current element into the heap
                pq.push(nums[i]);
            }
        }
        
        // The top of the heap contains the k-th largest element
        return pq.top();
    }
};
