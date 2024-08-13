class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        vector<int> currInt = intervals[0];

        for(int i = 1;i<intervals.size();i++){
            if(currInt[1]>=intervals[i][0]){
                currInt[1]=max(currInt[1],intervals[i][1]);
            }
            else{
                ans.push_back(currInt);
                currInt=intervals[i];
            }
        }
        ans.push_back(currInt);
        return ans;
    }
};