//给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得： 
//
// 
// left 中的每个元素都小于或等于 right 中的每个元素。 
// left 和 right 都是非空的。 
// left 要尽可能小。 
// 
//
// 在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。 
//
// 
//
// 示例 1： 
//
// 输入：[5,0,3,8,6]
//输出：3
//解释：left = [5,0,3]，right = [8,6]
// 
//
// 示例 2： 
//
// 输入：[1,1,1,0,6,12]
//输出：4
//解释：left = [1,1,1,0]，right = [6,12]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= A.length <= 30000 
// 0 <= A[i] <= 10^6 
// 可以保证至少有一种方法能够按题目所描述的那样对 A 进行划分。 
// 
//
// 
// Related Topics 数组 
// 👍 57 👎 0

// 找到第一个这样的位置：左边的最大值小于等于右边的最小值


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


class Solution {
public:
    int partitionDisjoint(vector<int> &A) {
        int len = A.size();
        VI left(A.size(), 0), right(A.size(), 0);
        left[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
            left[i] = max(left[i - 1], A[i]);
        }
        right[len - 1] = A[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], A[i]);
        }
        for (int i = 0; i < len - 1; i++) {
            if (left[i] <= right[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
