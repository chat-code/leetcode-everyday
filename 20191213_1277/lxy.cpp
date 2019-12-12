#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using VI = vector<int>;

class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = int(matrix.size()), n = int(matrix[0].size());
    int res = 0;
    for (int i = 0; i < m; i++)
      {
	for (int j = 0; j < n; j++)
	  {
	    if (!matrix[i][j]) continue;
	    int i1 = i - 1, j1 = j - 1;
	    if (i1 >= 0 && j1 >= 0 && matrix[i1][j1])
	      {
		int len = matrix[i1][j1];
		int len1 = 0, len2 = 0;

		for (int k = 1; k <= len; k++, len1++)
		  if (!matrix[i - k][j])
		    {
		      break;
		    }
		for (int k = 1; k <= len; k++, len2++)
		  if (!matrix[i][j - k])
		    {
		      break;
		    }
		matrix[i][j] += min(min(len1, len2), len);
	      }
	    res += matrix[i][j];
	  }
      }

    return res;
  }
};

int main()
{
  vector<VI> v1{{0,1,1,1},{1,1,1,1},{0,1,1,1}};
  Solution a;
  cout << a.countSquares(v1) << endl;

  vector<VI> v2{{0,1,1,1}};
  cout << a.countSquares(v2) << endl;

  return 0;
}
