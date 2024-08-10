class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxProfit= INT_MIN;
        for(int i =0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxProfit = max(maxProfit,prices[i]-mini);
        }
        return maxProfit;
    }
};