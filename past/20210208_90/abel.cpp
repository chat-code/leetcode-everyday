#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> a, cur;
  vector<vector<int>> res;
  int n;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur); return;
    }

    int cnt = 0;
    while (k + cnt < n && a[k + cnt] == a[k]) ++cnt;

    for (int i = 0; i <= cnt; ++i) {
      dfs(k + cnt);
      cur.push_back(a[k]);
    }

    for (int i = 0; i <= cnt; ++i) cur.pop_back();
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    a = nums;
    n = nums.size();
    dfs(0);

    return res;
  }
};

int main() {
  vector<int> v {1, 2, 3};
  Solution a;
  a.subsetsWithDup(v);

  return 0;
}
