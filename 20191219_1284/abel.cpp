#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
  unordered_map<string, int> sol;
  int m, n;
  string i2str(int a, int len)
  {
    string res;
    int j = 0;
    while (j++ < len || a)
      {
        if (a&1) res = "1" + res;
        else res = "0" + res;
        if (a > 0)
          a >>= 1;
      }
    return res;
  }
  void init(int le)
  {
    VS ms;
    string t;
    set<string> todo;
    for (int i = 0; i < (1<<le); i++)
      {
        t = i2str(i, le);
        ms.push_back(t);
        sol[t] = -1;
        todo.insert(t);
      }
    t = ms[0];
    sol[t] = 0;
    todo.erase(t);
    queue<string> q;
    q.push(t);
    while (!q.empty())
      {
        t = q.front();
        q.pop();
        VS done;
        for (auto &it : todo)
          {
            if (check(it, t))
              {
                done.push_back(it);
                sol[it] = sol[t] + 1;
                q.push(it);
              }
          }
        for (auto it : done)
          todo.erase(it);
      }
  }

  bool check(string a, string b)
  {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (flip(a, i, j) == b)
            return true;
    return false;
  }
  string flip(string a, int x, int y)
  {
    VS am(m);
    for (int i = 0, j = 0; i < m; i++, j += n)
      {
        am[i] = a.substr(j, n);
      }
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    am[x][y] = fc(am[x][y]);
    for (int i = 0; i < 4; i++)
      {
        int x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n)
            am[x1][y1] = fc(am[x1][y1]);
      }
    string res;
    for (int i = 0; i < m; i++)
      res += am[i];
    return res;
  }
  char fc(char c)
  {
    if (c == '0') return '1';
    else return '0';
  }

  int minFlips(vector<vector<int>>& mat) {
    m = int(mat.size());
    n = int(mat[0].size());
    if (m == 1 && n == 1)
      return mat[0][0];
    init(m * n);

    string t;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        t += mat[i][j] + '0';
    return sol[t];
  }
};

int main(void)
{
  Solution a;
  vector<VI> v1 {{0,0},{0,1}};
  a.minFlips(v1);

  return 0;
}
