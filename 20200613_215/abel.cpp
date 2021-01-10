//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法 
// 👍 845 👎 0

/*
 * 方法一：利用快速排序的特性，一趟扫描之后，pivot 的位置不再改变，因此只要找到第 k 个 pivot 即可。
 * 观察 pivot 的位置和 k 比较，这样只需要考虑 k 所在的那部分即可，另外一部分可以忽略。
 *
 * 方法二：维护一个大小为 k 的最小堆。堆顶元素即为所求。
 */

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



//leetcode submit region begin(Prohibit modification and deletion)

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    void myqsort(VI &a, int left, int right, int k, int &res) {
        if (left == right) {
            res = a[left];
            return;
        }
        int i = left + 1, j = right, p = a[left];
        while (i < j) {
            while (i < j && a[i] >= p) ++i;
            while (j > i && a[j] < p) --j;
            if (i < j) swap(a[i], a[j]);
        }
        if (a[j] < p) --j;
        swap(a[j], a[left]);
        if (j == k - 1) {
            res = a[j];
            return;
        } else if (j > k - 1) {
            myqsort(a, left, j-1, k, res);
        } else {
            myqsort(a, j + 1, right, k, res);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        int res;
        myqsort(nums, 0, nums.size() - 1, k, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
