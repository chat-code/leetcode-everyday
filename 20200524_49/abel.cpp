/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 * 把每个单词中的字母排序得到一个字符串，这个字符串对应一个原单词列表
 */

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    string to_sort(string& a) {
        string b;
        vector<char> va(a.size(), '\0');
        for (auto i = 0; i < a.size(); i++) {
            va[i] = a[i];
        }
        sort(va.begin(), va.end());
        for (auto &c : va) {
            b += c;
        }
        return b;
    }
    vector<vector<string>> groupAnagrams(
        vector<string>& strs) {
        map<string, vector<string>> nmap;
        for (auto& str : strs) {
            nmap[to_sort(str)].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = nmap.begin();
            it != nmap.end(); ++it) {
                res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end

