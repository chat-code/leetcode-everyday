//我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”： 
//
// 
// B.length >= 3 
// 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B
//[B.length - 1] 
// 
//
// （注意：B 可以是 A 的任意子数组，包括整个数组 A。） 
//
// 给出一个整数数组 A，返回最长 “山脉” 的长度。 
//
// 如果不含有 “山脉” 则返回 0。 
//
// 
//
// 示例 1： 
//
// 输入：[2,1,4,7,3,2,5]
//输出：5
//解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
// 
//
// 示例 2： 
//
// 输入：[2,2,2]
//输出：0
//解释：不含 “山脉”。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= A.length <= 10000 
// 0 <= A[i] <= 10000 
// 
// Related Topics 双指针 
// 👍 167 👎 0

// 分上升、下降两个阶段，做好标记。在下降阶段维护最大值。

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestMountain(vector<int> &a) {
        int len = a.size(), res = 0;
        if (len <= 2) return res;
        int p1 = 0, p2;
        int flag = 0;

        for (int i = 1; i < len; ++i) {
            if (a[i] > a[i - 1]) {
                if (flag == 0 || flag == 2) {
                    // init
                    p1 = i - 1;
                    flag = 1;
                }
            } else if (a[i] < a[i - 1]) {
                if (flag == 1) {
                    flag = 2;
                    int tmp = i - p1 + 1;
                    if (tmp >= 3) {
                        res = max(res, tmp);
                    }
                } else if (flag == 2) {
                    int tmp = i - p1 + 1;
                    if (tmp >= 3) {
                        res = max(res, tmp);
                    }
                }
            } else {
                p1 = i;
                flag = 0;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
