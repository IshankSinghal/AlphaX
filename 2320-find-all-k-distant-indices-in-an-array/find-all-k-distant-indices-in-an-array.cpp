class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();
        vector<int> ans;

        // int i = 0;
        int j = 0;

        while (j < n) {
            if (nums[j] == key) {
                int i =0;
                while (i < n) {
                    if (abs(i - j) <= k) {
                        if(find(ans.begin(), ans.end(), i) == ans.end()){
                            ans.push_back(i);
                        }
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};