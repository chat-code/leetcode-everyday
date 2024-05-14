/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 * 
 * 一種思路：不斷尋找 abc 字符串，如果找到，刪除它，求解剩餘字符串。
 * 
 * 另外一種更好的思路：
 * 使用棧，遇到 c 檢查棧頂的 2 個元素是否是 ab
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution2 {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        string target = "abc";
        size_t pos = s.find(target);
        if (pos == string::npos) return false;
        return isValid(s.substr(0, pos) + s.substr(pos + 3));
    }
};

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'c') {
                if (st.size() < 2) return false;
                if (st.top() != 'b') return false;
                st.pop();
                if (st.top() != 'a') return false;
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};
// @lc code=end
