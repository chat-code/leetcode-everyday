#include <string>
#include <vector>

using namespace std;

class Solution {
public:

  string mask_email(string s) {
    string name1;
    int pos = s.find('@');
    for (int i = 0; i < pos; ++i) name1 += s[i];

    string res;
    res += tolower(name1[0]);
    res += "*****";
    res += tolower(name1[name1.size() - 1]);

    for (int i = pos; i < int(s.size()); ++i) {
      if (isalpha(s[i])) res += tolower(s[i]);
      else res += s[i];
    }

    return res;
  }

  string mask_phone(string s) {
    vector<char> a;
    for (auto &c : s) {
      if (isdigit(c)) a.push_back(c);
    }

    string res;
    if (a.size() > 10) {
      res += "+" + string(a.size() - 10, '*') + "-";
    }

    res += "***-***-";
    for (int i = a.size() - 4; i < int(a.size()); ++i)
      res += a[i];

    return res;
  }

    string maskPII(string s) {
      if (s.find('@') != string::npos) {
        return mask_email(s);
      }

      return mask_phone(s);
    }
};
