const int N = 100010;
int son[N][26], cnt[N], idx = 0;

void insert(string s) {
  int p = 0;
  for (int i = 0; i < s.size(); ++i) {
    int u = s[i] - 'a';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
  cnt[p]++;
}

string query(string s) {
  int p = 0;
  string res;

  for (int i = 0; i < s.size(); ++i) {
    int u = s[i] - 'a';
    if (!son[p][u]) return s;
    p = son[p][u];
    res += s[i];
    if (cnt[p]) return res;
  }
  return res;
}

class Solution {
public:
  string replaceWords(vector<string>& d, string s) {
    idx = 0;
    memset(cnt, 0, sizeof cnt);
    memset(son, 0, sizeof son);

    for (auto &x : d) insert(x);

    vector<string> v;
    stringstream ss(s);
    string t;

    while (ss >> t) {
      v.push_back(query(t));
    }
    string res;

    for (int i = 0; i < v.size(); ++i) {
      res += v[i];
      if (i != v.size() - 1) res += ' ';
    }

    return res;
  }
};
