// Date: Mon Sep 13 13:23:09 2021

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
    vector<int> decompressRLElist(vector<int>& a) {
      VI res;
      int n = a.size();
      for (int i = 0; i < n - 1; i += 2) {
	while (a[i]--) {
	  res.push_back(a[i+1]);
	}
      }
      return res;
    }
};
