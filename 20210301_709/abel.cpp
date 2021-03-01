//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入: "Hello"
//输出: "hello" 
//
// 示例 2： 
//
// 
//输入: "here"
//输出: "here" 
//
// 示例 3： 
//
// 
//输入: "LOVELY"
//输出: "lovely"
// 
// Related Topics 字符串 
// 👍 142 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string toLowerCase(string s) {
        int t = 'a' - 'A';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += t;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
