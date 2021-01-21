//实现 strStr() 函数。 
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
//果不存在，则返回 -1。 
//
// 示例 1: 
//
// 输入: haystack = "hello", needle = "ll"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: haystack = "aaaaa", needle = "bba"
//输出: -1
// 
//
// 说明: 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
// Related Topics 双指针 字符串 
// 👍 676 👎 0


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
    int strStr(string haystack, string needle) {
        int m, n;
        m = needle.size();
        n = haystack.size();

        if (m == 0) return 0;

        vector<char> p(m + 1), s(n + 1);
        VI ne(m + 1, 0);
        for (int i = 0; i < m; ++i) p[i + 1] = needle[i];
        for (int i = 0; i < n; ++i) s[i + 1] = haystack[i];

        for (int i = 2, j = 0; i <= m; ++i) {
            while (j && p[i] != p[j + 1]) {
                j = ne[j];
            }
            if (p[i] == p[j + 1]) ++j;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= n; ++i) {
            while (j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) ++j;
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
