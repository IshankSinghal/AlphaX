//OPTIMIZED

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int l = n-1;
            while(j<l){
                long long sum = nums[i]+nums[j];
                sum+= nums[l];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[l]});
                    j++;l--;
                    while( j<l && nums[j]==nums[j-1]) j++;
                    while( j<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum<0) j++;
                else l--;
            }
        }
        return ans;
    }
};