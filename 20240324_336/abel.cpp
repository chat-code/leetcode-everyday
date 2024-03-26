// Date: Tue Mar 26 13:25:43 2024

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

const ull Pr = 131;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

// For LeetCode
#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#ifdef _DEBUG
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif
// End of LeetCode

const int N = 2000100;
int idx, son[N][26];

struct Po {
  set<int> pal;
  bool is;
  int pos;
};

Po tree[N];

void Init(int n) {
  idx = 0;
  For1(i, 0, n) {
    tree[i] = Po{};
    For(j, 0, 26) son[i][j] = 0;
  }
}

bool check(int l, int r, string &s) {
  bool flag = true;
  for (int j = l, k = r; j < k; ++j, --k) {
    if (s[j] != s[k]) {
      flag = false;
      break;
    }
  }
  return flag;
}

void Insert(string s, int pos) {
  int p = 0, len = SZ(s);

  if (check(0, len - 1, s)) {
    tree[p].pal.insert(pos);
  }

  For(i, 0, len) {
    int u = s[i] - 'a';
    if (!son[p][u])
      son[p][u] = ++idx;
    p = son[p][u];

    if (check(i + 1, len - 1, s)) {
      tree[p].pal.insert(pos);
    }
  }
  tree[p].pal.insert(pos);
  tree[p].is = true;
  tree[p].pos = pos;
}

set<int> Find(string s) {
  int len = SZ(s), p = 0;
  reverse(all(s));

  set<int> ans;

  if (check(0, len - 1, s)) {
    if (tree[p].is) {
      ans.insert(tree[p].pos);
    }
  }

  bool fin = true;
  For(i, 0, len) {
    int u = s[i] - 'a';
    if (check(i, len - 1, s) && tree[p].is) {
      ans.insert(tree[p].pos);
    }

    if (!son[p][u]) {
      fin = false;
      break;
    }
    p = son[p][u];
  }

  if (fin) {
    for (auto x : tree[p].pal) {
      ans.insert(x);
    }
  }

  return ans;
}

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &a) {
    int sum = 0;
    for (auto x : a)
      sum += SZ(x);

    Init(sum);

    vector<VI> ans;
    int n = SZ(a);

    For(i, 0, n) {
      auto tmp = Find(a[i]);

      for (auto x : tmp) {
        ans.pb({x, i});
      }

      Insert(a[i], i);
    }

    Init(sum);

    Rof(i, 0, n) {
      auto tmp = Find(a[i]);

      for (auto x : tmp) {
        if (x > i)
          ans.pb({x, i});
      }

      Insert(a[i], i);
    }

    return ans;
  }
};

#ifdef _DEBUG

int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solution a;
  vector<string> a_{"abcd", "dcba", "lls", "s", "sssll"};
  auto res = a.palindromePairs(a_);
  dbg(res);

  a_ = vector<string>{"bat", "tab", "cat"};
  res = a.palindromePairs(a_);
  dbg(res);

  a_ = vector<string>{"a", ""};
  res = a.palindromePairs(a_);
  dbg(res);

  a_ = vector<string>{"a", "abc", "aba", ""};
  res = a.palindromePairs(a_);
  dbg(res);

  a_ = vector<string>{"a", "b", "c", "ab", "ac", "aa"};
  res = a.palindromePairs(a_);
  dbg(res);

  a_ = vector<string>{"a", "aa", "aaa"};
  res = a.palindromePairs(a_);
  dbg(res);

  return 0;
}

#endif
