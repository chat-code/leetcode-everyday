using VI = vector<int>;

VI Add(VI &a, VI &b) {
  VI c;
  int t = 0, n = a.size(), m = b.size();

  for (int i = 0; i < n || i < m; ++i) {
    if (i < n) t += a[i];
    if (i < m) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t) c.push_back(t);

  return c;
}

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& a, int k) {
    VI res;

    reverse(a.begin(), a.end());
    VI b;
    while (k) {
      b.push_back(k % 10);
      k /= 10;
    }

    res = Add(a, b);
    reverse(res.begin(), res.end());
    return res;
  }
};
