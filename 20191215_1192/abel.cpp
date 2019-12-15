#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using VI = vector<int>;
using SI = stack<int>;


class Solution {
public:
  vector<VI> res;
  int timer;
  VI low, id;
  VI vis;
  vector<VI> g;
  
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    timer = 0;
    low.resize(n, -1);
    id.resize(n, -1);
    g.resize(n, VI{});
    vis.resize(n, 0);
    
    for (auto &x: connections)
      {
	g[x[0]].push_back(x[1]);
	g[x[1]].push_back(x[0]);
      }
    
    for (int i = 0; i < n; i++)
      if (!vis[i])
	dfs(i, -1);
    
    return res;
  }
  void dfs(int c, int p) 
  {
    low[c] = id[c] = timer++;
    vis[c] = 1;
    for (auto x: g[c])
      {
	if (x == p) continue;
	if (!vis[x])
	  {
	    dfs(x, c);
	    low[c] = min(low[c], low[x]);
	    if (id[c] < low[x])
	      res.push_back(VI{c, x});
	  }
	else 
	  {
	    low[c] = min(low[c], id[x]);
	  }
      }
  }
};

int main(void)
{
  Solution a;
  vector<VI> v1{{0, 1}, {1, 2} , { 2, 0} , {1, 3}} ;
  vector<VI> res = a.criticalConnections(4, v1);
  for (auto a : res)
    {
      cout << a[0] << " " << a[1] << endl;
    }
  
  return 0;
}
