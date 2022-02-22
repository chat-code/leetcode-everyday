// Date: Tue Feb 22 20:28:24 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

const int N = 35;
int primes[N], cnt;
bool st[N];

void Init() {
  cnt = 0;
  memset(st, false, sizeof st);
}

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = ll(i) * i; j <= n; j += i) {
        st[j] = true;
      }
    }
  }
}

class Solution {
public:
  int numberOfGoodSubsets(vector<int>& a) {
    Init();
    get_primes(30);

    map<int, int> m;
    for (auto &x : a) m[x]++;

    ll mask = 1LL << cnt;
    vector<ll> d(mask, 0);
    d[0] = 1;

    for (int i = 2; i <= 30; ++i) {
      if (!m[i]) continue;

      int k = i;
      bool flag = true;
      ll cur = 0;

      for (int j = 0; j < cnt; ++j) {
        int p = 0;
        while (k > 1 && k % primes[j] == 0) {
          k /= primes[j];
          ++p;
          cur = cur | (1LL << j);
        }

        if (p > 1) {
          flag = false;
          break;
        }
      }

      if (!flag) continue;

      for (ll pre = mask - 1; pre >= 0; --pre) {
        if ((pre & cur)) continue;
        d[pre | cur] = (d[pre | cur] + d[pre] * m[i] % MOD) % MOD;
      }
    }

    ll res = 0;
    for (ll i = 1; i < mask; ++i) res = (res + d[i]) % MOD;
    if (m[1]) {
      for (int i = 0; i < m[1]; ++i) res = (res * 2) % MOD;
    }

    return res;
  }
};
