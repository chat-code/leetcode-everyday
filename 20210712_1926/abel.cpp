// Date: Sun Jul 11 00:24:15 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>

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
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 110;

class Solution {
public:
  int n, m;
  bool st[N][N];
  int b[N][N];
  
  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
  
  
  int nearestExit(vector<vector<char>>& a, vector<int>& en) {
    int res = -1;
    n = a.size(); m = a[0].size();
    memset(st, false, sizeof st);
    memset(b, 0x3f, sizeof b);
    queue<PII> que;
    que.push(PII(en[0], en[1]));
    b[en[0]][en[1]] = 0;
    st[en[0]][en[1]] = true;
      
    while (!que.empty()) {
      auto t = que.front(); que.pop();
      int x = t.first, y = t.second, x1, y1;
      if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
        if (x != en[0] || y != en[1]) {
          res = b[x][y];
          break;
        }
      }
	
      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (check(x1, y1) && a[x1][y1] == '.') {
          if (!st[x1][y1]) {
            que.push(PII(x1, y1));
            st[x1][y1] = true;
	      
            if (b[x1][y1] > b[x][y] + 1)
              b[x1][y1] = b[x][y] + 1;
          }
        }
      }
    }
      
    return res;
  }
};
