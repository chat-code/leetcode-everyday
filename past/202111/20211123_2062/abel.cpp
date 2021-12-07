// Date: Mon Nov 29 15:09:37 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
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
typedef vector<int> VI;
typedef pair<int, int> PII;

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

const int N = 30;
int cnt[N];

class Solution {
public:
  bool check_vowel() {
    string s = "aeiou";
    for (auto &c : s) {
      if (cnt[c - 'a'] == 0) return false;
    }
    return true;
  }

  bool is_vowel(char c) {
    string s = "aeiou";
    for (auto &x : s)
      if (x == c) return true;
    return false;
  }

  int countVowelSubstrings(string a) {
    memset(cnt, 0, sizeof cnt);

    int res = 0;
    int n = a.size(), l = 0, r = 0;

    for (int i = 0, j = 0; i < n; ++i) {
      if (!is_vowel(a[i])) {
        l = i + 1;
        continue;
      }

      r = i;
      while (r < n && is_vowel(a[r])) {
        ++r;
      }
      r--;

      memset(cnt, 0, sizeof cnt);
      for (i = j = l; i <= r; ++i) {
        cnt[a[i] - 'a']++;
        if (check_vowel()) {
          while (j < i && cnt[a[j] - 'a'] > 1 && check_vowel()) {
            cnt[a[j] - 'a']--;
            ++j;
          }
          res += j - l + 1;
        }
      }

      i = r;
    }

    return res;
  }
};
