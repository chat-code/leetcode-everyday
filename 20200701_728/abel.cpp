//自除数 是指可以被它包含的每一位数除尽的数。 
//
// 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。 
//
// 还有，自除数不允许包含 0 。 
//
// 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。 
//
// 示例 1： 
//
// 
//输入： 
//上边界left = 1, 下边界right = 22
//输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// 
//
// 注意： 
//
// 
// 每个输入参数的边界满足 1 <= left <= right <= 10000。 
// 
// Related Topics 数学 
// 👍 118 👎 0


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
    bool check(int n) {
        int t = n;
        if (t % 10 == 0) return false;
        while (t) {
            int k = t % 10;
            if (k == 1) {
                t /= 10;
                continue;
            }
            if (k == 0 || (n % k != 0)) return false;
            t /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        VI res;
        for (int i = left; i <= right; i++) {
            if (check(i)) res.push_back(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
