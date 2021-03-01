//给定一个由不同正整数的组成的非空数组 A，考虑下面的图： 
//
// 
// 有 A.length 个节点，按从 A[0] 到 A[A.length - 1] 标记； 
// 只有当 A[i] 和 A[j] 共用一个大于 1 的公因数时，A[i] 和 A[j] 之间才有一条边。 
// 
//
// 返回图中最大连通组件的大小。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：[4,6,15,35]
//输出：4
//
// 
//
// 示例 2： 
//
// 
//输入：[20,50,9,63]
//输出：2
//
// 
//
// 示例 3： 
//
// 
//输入：[2,3,6,7,4,12,21,39]
//输出：8
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 20000 
// 1 <= A[i] <= 100000 
// 
// Related Topics 并查集 数学 
// 👍 40 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

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
#include <cmath>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

const int N = 100009;
int fa[N], sz[N], prime[N], p_len, is_prime[N];

int Find(int x) {
    if (fa[x] == 0) return fa[x] = x;
    if (fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx == ry) return;
    if (sz[rx] == 0) sz[rx] = 1;
    if (sz[ry] == 0) sz[ry] = 1;
    if (sz[rx] < sz[ry]) swap(rx, ry);
    fa[ry] = rx;
    sz[rx] += sz[ry];
}

class Solution {
public:
    int largestComponentSize(vector<int> &A) {
        int n = A.size();
        memset(fa, 0, sizeof fa);
        memset(sz, 0, sizeof sz);
        memset(prime, 0, sizeof prime);
        memset(is_prime, 0, sizeof is_prime);

        int top = 0;
        for (int i = 0; i < n; ++i) top = max(top, A[i]);

        for (int i = 2; i < top + 1; i++) {
            if (!is_prime[i])
                for (int j = i * 2; j < N; j += i) {
                    is_prime[j] = 1;
                }
        }
        p_len = 0;
        for (int i = 2; i < top + 1; ++i) {
            if (!is_prime[i])
                prime[p_len++] = i;
        }

        for (int i = 0; i < n; ++i) {
            int t = A[i];
            while (t > 1) {
                for (int j = 0; j < p_len && prime[j] <= t; ++j) {
                    if (t % prime[j] == 0) {
                        Union(prime[j], A[i]);
                        t /= prime[j];
                        break;
                    }
                }
            }
        }

        int res = 0;
        map<int, int> ma;
        for (int i = 0; i < n; ++i) {
            int x = Find(A[i]);
            ma[x]++;
            res = max(ma[x], res);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
