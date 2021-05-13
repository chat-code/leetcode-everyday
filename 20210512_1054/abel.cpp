using VI = vector<int>;
using PII = pair<int, int>;

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& a) {
    VI res;
    int n = a.size();

    map<int, int> m;
    for (auto &x : a) m[x]++;

    priority_queue<PII, vector<PII>, less<PII>> cnts;
    for (auto &x : m) {
      cnts.push({x.second, x.first});
    }

    while (cnts.size() > 1) {
      auto x = cnts.top();
      cnts.pop();
      auto y = cnts.top();
      cnts.pop();

      x.first--;
      y.first--;
      res.push_back(x.second);
      res.push_back(y.second);

      if (x.first > 0) cnts.push(x);
      if (y.first > 0) cnts.push(y);
    }
    if (cnts.size() == 1) {
      auto x = cnts.top();
      res.push_back(x.second);
    }

    return res;
  }
};
