//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 
//
// 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// 
// Related Topics 并查集 数组 
// 👍 653 👎 0


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

map<int, int> fa, sz;

int Find(int x) {
    auto it = fa.find(x);
    if (it == fa.end()) {
        return fa[x] = x;
    }
    if (fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (sz.find(rx) == sz.end()) sz[rx] = 1;
    if (sz.find(ry) == sz.end()) sz[ry] = 1;
    if (rx == ry) return;
    if (sz[rx] < sz[ry]) swap(rx, ry);
    fa[ry] = rx;
    sz[rx] += sz[ry];
}

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        set<int> s;
        int n = nums.size();
        if (n == 0) return 0;

        for (int i = 0; i < n; ++i) {
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                sz[nums[i]] = 1;
                fa[nums[i]] = nums[i];
            }
            int a = nums[i] - 1, b = nums[i] + 1;
            if (s.find(a) != s.end()) {
                Union(a, nums[i]);
            }
            if (s.find(b) != s.end()) {
                Union(b, nums[i]);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int x = Find(nums[i]);
            res = max(res, sz[x]);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
