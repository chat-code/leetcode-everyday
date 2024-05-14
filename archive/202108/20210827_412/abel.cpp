// Date: Wed Sep  1 18:44:53 2021

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
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; ++i) {
      string tmp;
      if (i % 3 == 0 && i % 5 == 0) {
	tmp = "FizzBuzz";
      } else if (i % 3 == 0) {
	tmp = "Fizz";
      } else if (i % 5 == 0) {
	tmp = "Buzz";
      } else {
	tmp = to_string(i);
      }

      res.push_back(tmp);
    }
    return res;
  }
};
