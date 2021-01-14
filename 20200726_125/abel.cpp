//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 示例 1: 
//
// 输入: "A man, a plan, a canal: Panama"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "race a car"
//输出: false
// 
// Related Topics 双指针 字符串 
// 👍 311 👎 0


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
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0) return true;
        int i = 0, j = len - 1;
        while (i < j) {
            char a, b;
            while (i < j && !(isdigit(s[i]) || isalpha(s[i]))) {
                ++i;
            }
            while (i < j && !(isdigit(s[j]) || isalpha(s[j]))) {
                --j;
            }
            if (i >= j) return true;
            a = s[i];
            b = s[j];
            if (isalpha(a)) a = tolower(a);
            if (isalpha(b)) b = tolower(b);
            if (a != b) return false;
            ++i;
            --j;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
