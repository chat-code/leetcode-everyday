// Date: Wed Sep  1 20:03:17 2021

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

  vector<string> g;
  bool success(char c) {
    bool mark = true;

    for (int i = 0; i < 3; ++i) {
      bool mark = true;
      for (int j = 0; j < 3; ++j) {
	if (g[i][j] != c) {
	  mark = false;
	  break;
	}
      }
      if (mark) return true;
    }

    for (int j = 0; j < 3; ++j) {
      bool mark = true;
      for (int i = 0; i < 3; ++i) {
	if (g[i][j] != c) {
	  mark = false;
	  break;
	}
      }
      if (mark) return true;
    }

    mark = true;
    for (int i = 0; i < 3; ++i) {
      if (g[i][i] != c) {
	mark = false;
	break;
      }
    }
    if (mark) return true;

    mark = true;
    for (int i = 0; i < 3; ++i) {
      if (g[i][2 - i] != c) {
	mark = false;
	break;
      }
    }
    if (mark) return true;

    return false;
  }

  int countc(char c) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
	if (g[i][j] == c) res++;
      }
    }
    return res;
  }

  bool validTicTacToe(vector<string>& a) {
    g = a;
    int cx = countc('X'), co = countc('O');
    if (cx == co) {
      return !success('X');
    } else if (cx == co + 1) {
      return !success('O');
    } else return false;
  }
};
