class Solution {
public:
  int trap(vector<int>& a) {
    int n = a.size(), res = 0;

    if (!n) return res;

    stack<int> stk;
    stk.push(0);

    for (int i = 1; i < n; ++i) {
      while (!stk.empty() && a[stk.top()] < a[i]) {
        int j = stk.top();
        stk.pop();
        if (stk.empty()) break;

        int k = stk.top();
        res += (min(a[k], a[i]) - a[j]) * (i - k - 1);
      }
      stk.push(i);
    }

    return res;
  }
};
