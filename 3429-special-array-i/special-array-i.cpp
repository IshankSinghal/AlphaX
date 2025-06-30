class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        if (nums.size() == 1)
            return true;

        int i = 0;
        int j = 1;
        while (j < nums.size()) {
            if (((nums[i] % 2 == 0) && (nums[j] % 2 == 0)) ||
                ((nums[i] % 2 == 1) && (nums[j] % 2 == 1))) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
};