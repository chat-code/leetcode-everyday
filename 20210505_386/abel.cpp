using namespace std;
using VI = vector<int>;

class Solution {
public:
  VI res;
  int n;

  void dfs(int x) {
    if (x > n) return;

    int start = 0;
    if (x) {
      res.push_back(x);
    } else {
      start++;
    }

    for (int i = start; i <= 9; ++i) {
      int t = x * 10 + i;
      if (t > n) break;
      dfs(t);
    }
  }

  vector<int> lexicalOrder(int _n) {
    n = _n;
    dfs(0);

    return res;
  }
};
