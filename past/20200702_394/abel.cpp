//给定一个经过编码的字符串，返回它解码后的字符串。 
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。 
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。 
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 
//
// 
//
// 示例 1： 
//
// 输入：s = "3[a]2[bc]"
//输出："aaabcbc"
// 
//
// 示例 2： 
//
// 输入：s = "3[a2[c]]"
//输出："accaccacc"
// 
//
// 示例 3： 
//
// 输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
// 
//
// 示例 4： 
//
// 输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
// 
// Related Topics 栈 深度优先搜索 
// 👍 624 👎 0


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
#include <iomanip>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    string get_next(int &i, string &s) {
        stack<char> st;
        st.push(s[i]);
        ++i;
        int len = s.length();
        string res;
        while (!st.empty() && i < len) {
            if (s[i] == ']') {
                st.pop();
            } else if (s[i] == '[') {
                st.push(s[i]);
            }
            if (!st.empty()) {
                res += s[i];
            }
            ++i;
        }
        return res;
    }

    string dfs(string s) {
        int len = s.size();
        string res;
        if (len == 0) return res;

        string prefix, next, rest;
        int i;
        for (i = 0; i < len; i++) {
            if (!isdigit(s[i])) {
                prefix = prefix + s[i];
            } else {
                break;
            }
        }
        if (i == len) {
            return prefix;
        }

        int cnt = 0;
        for (; i < len; ++i) {
            if (isdigit(s[i])) {
                cnt = cnt * 10 + (s[i] - '0');
            } else {
                break;
            }
        }

        next = get_next(i, s);
        string mid = dfs(next);
        string mid1;
        while (cnt--) {
            mid1 += mid;
        }

        rest = s.substr(i);
        rest = dfs(rest);

        res = prefix + mid1 + rest;
        return res;
    }

    string decodeString(string s) {
        return dfs(s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
