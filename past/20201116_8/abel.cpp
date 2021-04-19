class Solution {
public:
  int myAtoi(string s) {
    int res = 0;
    int n = s.size();
    bool flag = true;
    int i = 0;

    while (i < n && isspace(s[i])) ++i;
    if (i == n) return res;

    if (s[i] == '-') {
      flag = false; ++i;
    }
    else if (s[i] == '+') {
      flag = true; ++i;
    }

    for (; i < n && isdigit(s[i]); ++i) {
      if (flag) {
        if (res > INT_MAX / 10) {
          res = INT_MAX; break;
        } else if (res == INT_MAX / 10) {
          if (s[i] - '0' > INT_MAX % 10) {
            res = INT_MAX; break;
          }
        }

        res = res * 10 + (s[i] - '0');
      } else {
        if (res < INT_MIN / 10) { res = INT_MIN; break; }
        else if (res == INT_MIN / 10) {
          if (-(s[i] - '0') < INT_MIN % 10) {
            res = INT_MIN; break;
          }
        }

        res = res * 10 - (s[i] - '0');
      }
    }

    return res;
  }
};
