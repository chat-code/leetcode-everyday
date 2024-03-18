#include <iostream>
#include <vector>

using namespace std;
using VI = vector<int>;

class Solution {
public:
  int maxSideLength(vector<vector<int>>& matrix, int threshold) {
    int m = int(matrix.size()), n = int(matrix[0].size());
    vector<VI> dp(m, VI(n, 0));
    vector<VI> row(m, VI(n, 0));

    for (int i = 0; i < m; i++)
      {
	for (int j = 0; j < n; j++)
	  {
	    if (j == 0)
	      row[i][j] = matrix[i][j];
	    else
	      row[i][j] = row[i][j-1] + matrix[i][j];
	    if (matrix[i][j] <= threshold)
	      dp[i][j] = 1;
	  }
      }

    int res = 0;
    for (int i = 0; i < m; i++)
      {
	for (int j = 0; j < n; j++)
	  {
	    if (!dp[i][j]) continue;
	    int i1 = i - 1, j1 = j - 1;

	    if (i1 >= 0 && j1 >= 0 && dp[i1][j1])
	      {
		int len = dp[i1][j1] + 2;
		// cout << "out len =" << len << endl;
		int tmp = 0;
		while (len)
		  {
		    tmp = 0;
		    for (int k = 0; k < len &&i>=k &&j+1>=len && i+1>=len; k++)
		      {
			if (j + 1 == len)
			  tmp += row[i-k][j];
			else
			  tmp += (row[i-k][j] - row[i-k][j-len]);
		      }
		    if (tmp <= threshold && j+1>=len &&i+1>=len)
		      {
			dp[i][j] = len;
			// cout << "len =" << len <<"tmp="<<tmp<<"i="<<i<<"j="<<j << endl;
			break;
		      }
		    len--;
		  }
	      }
	    res = max(res, dp[i][j]);
	  }
      }

    return res;
  }
};

int main(void)
{
  Solution a;
  vector<VI> v1{{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
  int th1 = 4;
  cout << a.maxSideLength(v1, th1) << endl; // 2

  vector<VI> v2{{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}};
  int th2 = 1;
  cout << a.maxSideLength(v2, th2) << endl; // 0

  vector<VI> v3{{28,39,98,91,7,99},{79,3,17,83,9,92},{81,73,42,27,67,70},{88,30,73,99,96,89},{27,59,0,1,65,79},{42,55,48,29,86,96}};
  int th3 = 24829;
  cout << a.maxSideLength(v3, th3) << endl; // 6

  vector<VI> v4{{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
  int th4=6;
  cout << a.maxSideLength(v4, th4) << endl; // 3

  return 0;
}
