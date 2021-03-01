//给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。 
//
// 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。 
//
// 
//
// 示例 1： 
//
// 输入：a = "abcd", b = "cdabcdab"
//输出：3
//解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
// 
//
// 示例 2： 
//
// 输入：a = "a", b = "aa"
//输出：2
// 
//
// 示例 3： 
//
// 输入：a = "a", b = "a"
//输出：1
// 
//
// 示例 4： 
//
// 输入：a = "abc", b = "wxyz"
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= a.length <= 104 
// 1 <= b.length <= 104 
// a 和 b 由小写英文字母组成 
// 
// Related Topics 字符串 
// 👍 122 👎 0

// 循环 a 字符串的位置去匹配 b 字符串，如果到 a 的末尾了之后，回到 a 的起始位置，同时循环次数递增
// 特殊情况：如果 b 到末尾了，但是 a 的位置在中间，此时也要递增，因为相当于匹配了 a 的前缀


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
    int repeatedStringMatch(string a, string b) {
        int res = 0, k = 0, j = 0, len = a.size(), lenb = b.size();
        for (int i = 0; i < len; ++i) {
            k = i;
            j = 0;
            while (j < lenb && a[k] == b[j]) {
                ++k;
                ++j;
                if (k == len) ++res;
                k %= len;
            }
            if (j == lenb) {
                if (k > 0) ++res;
                return res;
            } else {
                res = 0;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
