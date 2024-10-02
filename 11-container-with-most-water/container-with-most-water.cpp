class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxWater = INT_MIN;

        while (i < j) {
            int water_stored = (j - i) * min(height[i], height[j]);
            if (height[i] < height[j])
                i++;
            else
                j--;
            maxWater = max(maxWater, water_stored);
        }

        return maxWater;
    }
};