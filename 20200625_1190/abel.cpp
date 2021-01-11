//给出一个字符串 s（仅含有小写英文字母和括号）。 
//
// 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。 
//
// 注意，您的结果中 不应 包含任何括号。 
//
// 
//
// 示例 1： 
//
// 输入：s = "(abcd)"
//输出："dcba"
// 
//
// 示例 2： 
//
// 输入：s = "(u(love)i)"
//输出："iloveu"
// 
//
// 示例 3： 
//
// 输入：s = "(ed(et(oc))el)"
//输出："leetcode"
// 
//
// 示例 4： 
//
// 输入：s = "a(bcdefghijkl(mno)p)q"
//输出："apmnolkjihgfedcbq"
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 2000 
// s 中只有小写英文字母和括号 
// 我们确保所有括号都是成对出现的 
// 
// Related Topics 栈 
// 👍 59 👎 0

// 先找到匹配的括号的位置
// 遇到左括号就跳转到右括号，遇到右括号就跳转到左括号；同时改变方向


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
    string reverseParentheses(string s) {
        stack<int> poss;
        int len = s.size();
        map<int, int> ms;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                poss.push(i);
            } else if (s[i] == ')') {
                int k = poss.top();
                ms[k] = i;
                ms[i] = k;
                poss.pop();
            }
        }
        string res;
        int d = 1;
        for (int i = 0; i < len; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                d *= -1;
                i = ms[i];
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
