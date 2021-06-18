class Solution {
public:
  int maxProfit(vector<int>& prices) {
    const int n = prices.size();
    if (n == 1) return 0;
    vector<int> buy(n, 0);
    vector<int> sell(n, 0);
    
    buy[0] = -prices[0];
    buy[1] = max(-prices[0], -prices[1]);
    sell[1] = max(0, prices[1] - prices[0]);
    
    for (int i = 2; i < prices.size(); ++i) {
      buy[i] = max(buy[i - 1], -prices[i] + sell[i - 2]);
      sell[i] = max(sell[i - 1], prices[i] + buy[i - 1]);
    }
    
    return sell.back();
  }
};
