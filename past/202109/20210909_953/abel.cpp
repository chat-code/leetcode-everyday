// Date: Thu Sep  9 17:41:18 2021

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
  bool isAlienSorted(vector<string>& words, string order) {
    map<char, char> m;
    for (int i = 0; i < order.size(); ++i) {
      m[order[i]] = 'a' + i;
    }

    vector<string> w1s;
    for (auto &w : words) {
      string t;
      for (auto c : w) {
        t += m[c];
      }
      w1s.push_back(t);
    }

    vector<string> w2s = w1s;
    sort(w2s.begin(), w2s.end());
    for (int i = 0; i < w1s.size(); ++i) {
      if (w1s[i] != w2s[i]) return false;
    }
    return true;
  }
};
