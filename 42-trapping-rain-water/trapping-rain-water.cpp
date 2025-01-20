class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax = 0;
        int left = 0;
        int right = height.size()-1;

        int trappedWater = 0;

        while(left < right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    trappedWater += leftMax - height[left];
                }
                else leftMax = height[left];

                left++;
            }
            else{
                if(rightMax > height[right]){
                    trappedWater += rightMax - height[right];
                }
                else rightMax = height[right];

                right--;
            }
        }

        return trappedWater;
    }
};