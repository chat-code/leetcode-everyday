#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
  string maximumTimeV1(string time) {
    const char *s = time.c_str();
    char a[20];
    memcpy(a, s, strlen(s));

    if (a[4] == '?') a[4] = '9';
    if (a[3] == '?') a[3] = '5';

    if(a[0] == '?') {
      if (a[1] == '?') {
        a[0] = '2';
        a[1] = '3';
      } else if (a[1] >= '4') {
        a[0] = '1';
      } else {
        a[0] = '2';
      }
    } else if (a[0] == '2') {
      if (a[1] == '?') a[1] = '3';
    } else {
      if (a[1] == '?') a[1] = '9';
    }

    string res(a);
    return res;
  }

  bool check(string s, char a[]) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?' || s[i] == a[i]) continue;
      else return false;
    }
    return true;
  }

  string maximumTime(string time) {
    for (int i = 23; i >= 0; --i) {
      for (int j = 59; j >= 0; --j) {
        char str[20];
        sprintf(str, "%02d:%02d", i, j);
        if (check(time, str)) return str;
      }
    }

    return "";
  }
};
