class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        int m_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (min>prices[i]) {
                min = prices[i];
            }
            else {
                profit = prices[i]-min;
                if (profit>m_profit) {
                    m_profit = profit;
                }
            }
        }
         return m_profit;
    }
};