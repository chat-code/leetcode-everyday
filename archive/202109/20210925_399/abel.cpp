// Date: Sun Sep 26 15:43:03 2021

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
  map<string, string> fa;
  map<string, double> de;

  string Find(string x) {
    if (fa.find(x) == fa.end()) {
      fa[x] = x;
      de[x] = 1;
      return x;
    }
    if (fa[x] == x) return x;

    if (de.find(x) == de.end()) de[x] = 1;

    string tmp = Find(fa[x]);

    de[x] *= de[fa[x]];
    fa[x] = tmp;

    return fa[x];
  }

  void Union(string x, string y, double z) {
    string rx = Find(x), ry = Find(y);
    if (rx == ry) return;
    de[ry] = z;
    fa[ry] = rx;
  }

  vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vs, vector<vector<string>>& qs) {
    int n = vs.size();
    fa.clear();
    de.clear();
    for (int i = 0; i < n; ++i) {
      string x = eqs[i][0], y = eqs[i][1], rx = Find(x), ry = Find(y);
      if (rx == ry) continue;
      fa[ry] = rx;
      de[ry] = vs[i] * de[x] / de[y];
    }
    vector<double> res;
    for (auto &v : qs) {
      string x = v[0], y = v[1];
      if (fa.find(x) == fa.end() || fa.find(y) == fa.end()) {
        res.push_back(-1);
      } else {
        string rx = Find(x), ry = Find(y);
        if (rx != ry) res.push_back(-1);
        else res.push_back(de[y] / de[x]);
      }
    }
    return res;
  }
};
