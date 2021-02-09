/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
using ll = long long;

class Solution {
public:
  string fractionToDecimal(int _x, int _y) {
    if (_x == 0) return "0";

    ll x = _x, y = _y;
    int sig = 1;
    if (x < 0) x = -x, sig *= -1;
    if (y < 0) y = -y, sig *= -1;

    ll d = x / y;
    ll r = x % y;

    map<ll, int> pos;
    string res = to_string(d), rem;
    if (sig == -1) res = "-" + res;
    if (!r) return res;

    int j = 0, start = 0;
    bool flag = false;

    pos[r] = j++;

    while (r) {
      ll d = r * 10 / y;
      r = r * 10 % y;
      rem = rem + char('0' + d);

      if (pos.find(r) != pos.end()) {
        start = pos[r];
        flag = true;
        break;
      }
      pos[r] = j++;
    }
    res = res + ".";
    for (int i = 0; i < rem.size(); i++) {
      if (i == start && flag) {
        res = res + '(';
      }
      res = res + rem[i];
    }
    if (flag) res = res + ')';
    return res;
  }
};
// @lc code=end

#ifdef _DEBUG

int main() {
  Solution a;

  cout << a.fractionToDecimal(2, 3) << endl;
  cout << a.fractionToDecimal(1, 6) << endl;
  cout << a.fractionToDecimal(10, 6) << endl;
  cout << a.fractionToDecimal(1, 2) << endl;
  cout << a.fractionToDecimal(-2147483648, 1) << endl;

  return 0;
}

#endif

