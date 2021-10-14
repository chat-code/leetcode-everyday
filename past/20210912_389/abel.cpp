// Date: Mon Sep 13 13:31:01 2021

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
    char findTheDifference(string s, string t) {
      VI cs(26, 0), ct(26, 0);
      for (int i = 0; i < s.size(); ++i) cs[s[i] - 'a']++;
      for (int i = 0; i < t.size(); ++i) ct[t[i] - 'a']++;
      for (int i = 0; i < 26; ++i) {
	if (cs[i] != ct[i]) return 'a' + i;
      }
      return '0';
    }
};
