class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            int j = i + 1;
            while (j < len && prices[j] > prices[i])
                j++;
            if (j < len)
                prices[i] = prices[i] - prices[j];
        }
        return prices;
    }
};