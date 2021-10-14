// Date: Thu Sep 23 16:45:07 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

class Solution {
public:
  int count1(VI &v) {
    int res = 0;
    int a[11] {}, p[11] {};
    for (auto c : v) a[c] = 1;
    for (int i = 1; i <= 10; ++i) p[i] = p[i - 1] + a[i];
    if (p[5] - p[1] == 0) res++;
    if (p[9] - p[5] == 0) res++;
    if (!res && p[7] == p[3]) res++;
    return res;
  }

  int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
    int res = 0;

    map<int, VI> cols;

    for (auto &v : a) {
      cols[v[0]].push_back(v[1]);
    }
    res += (n - cols.size()) * 2;
    for (auto &p : cols) {
      res += count1(p.second);
    }

    return res;
  }
};
