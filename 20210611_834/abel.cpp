#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 10010, M = 20010;
int h[N], down[N], up[N], cnt[N];
int idx, e[M], ne[M], n;

void Add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(down, 0, sizeof down);
  memset(up, 0, sizeof up);
  memset(cnt, 0, sizeof cnt);
}

class Solution {
public:
  void dfs1(int u, int father) {
    cnt[u] = 1;
    down[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == father) continue;
      dfs1(j, u);
      down[u] += down[j] + cnt[j];
      cnt[u] += cnt[j];
    }
  }

  void dfs2(int u, int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == father) continue;
      up[j] = up[u] + down[u] - (down[j] + cnt[j]) + n - cnt[j];
      dfs2(j, u);
    }
  }

  vector<int> sumOfDistancesInTree(int _n, vector<vector<int> > &edges) {
    Init();
    for (auto &e : edges) {
      int a = e[0], b = e[1];
      Add(a, b), Add(b, a);
    }

    n = _n;
    dfs1(0, -1);
    dfs2(0, -1);

    vector<int> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(down[i] + up[i]);
    }
    return res;
  }

};
