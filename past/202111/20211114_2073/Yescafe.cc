class Solution {
public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int spent = tickets[k];
    for (int i = 0; i < k; ++i) {
      spent += min(tickets[i], tickets[k]);
    }
    for (int i = k + 1; i < tickets.size(); ++i) {
      spent += min(tickets[i], tickets[k] - 1);
    }
    return spent;
  }
};