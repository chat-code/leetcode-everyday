//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 3
//输出: [1,3,3,1]
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？ 
// Related Topics 数组 
// 👍 267 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;

    vector<int> getRow(int rowIndex) {
        ++rowIndex;

        VI res {1};
        if (rowIndex == 1) return res;
        res = VI(rowIndex, 0);
        res[0] = 1;
        VI pre(res);

        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!j || j == i - 1) res[j] = 1;
                else {
                    res[j] = pre[j] + pre[j - 1];
                }
            }
            pre = res;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
