class Solution {
public:

    void solve(vector<int>& nums, int ind, vector<int> subset, vector<vector<int>>& ans){
        
        ans.push_back(subset);

        for(int i = ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            solve(nums,i+1,subset,ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        solve(nums,0,subset,ans);
        return ans;
    }
};