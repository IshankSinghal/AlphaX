class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();
        int i = 0;

        while (i < n) {
            int j = i+1;

            while (j < n && prices[j] > prices[i]) {
                j++;
            }

            if (j < n) {
                prices[i] -= prices[j];
            }
            i++;
        }

        return prices;

        return prices;
    }
};