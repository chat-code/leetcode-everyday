class Solution {
public:
  using VI = vector<int>;
    int numberOfWeakCharacters(vector<vector<int>>& a) {
      sort(a.begin(), a.end(), [&](const VI& x, const VI& y) {
	if (x[0] < y[0]) return true;
	else if (x[0] > y[0]) return false;
	return x[1] < y[1];
      });
      
      int n = a.size();
      vector<int> b(n, -1);
      b[n - 1] = a[n - 1][1];
      for (int i = n - 2; i >= 0; --i) {
	b[i] = max(a[i][1], b[i + 1]);
      }
      
      int res {};
      for (int i = 0; i < n - 1; ++i) {
	int l = i + 1, r = n - 1, m;
	while (l < r) {
	  m = (l + r) / 2;
	  if (a[m][0] > a[i][0]) r = m;
	  else l = m + 1;
	}
	if (a[r][0] > a[i][0]) {
	  res += (b[r] > a[i][1]);
	}
      }
      
      return res;
    }
};
