/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

int fa[300], sz[300];

int Find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx == ry) return;
    if (sz[rx] < sz[ry]) swap(rx, ry);
    fa[ry] = rx;
    sz[rx] += sz[ry];
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 1 ; i <= n; ++i) {
            fa[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (a[i][j]) {
                    Union(i+1, j+1);
                }
            }
        }
        int res = 0;
        unordered_set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(Find(i));
        }
        res = s.size();
        return res;
    }
};
// @lc code=end
