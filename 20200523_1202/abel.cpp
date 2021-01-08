/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 * 
 * 并查集，实现的时候注意路径压缩
 * 一个集合内按照字符排序，再插入排序好的位置上
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> pos;
    vector<int> root;
    vector<int> rsize;
    void merge(int i, int j) {
        if (i == j) return;
        int r1 = find_root(i), r2 = find_root(j);
        if (r1 == r2) return;

        int sz1 = rsize[r1], sz2 = rsize[r2];
        if (sz1 > sz2) {
            root[j] = root[r2] = r1;
            rsize[r1] += rsize[r2];
        } else {
            root[i] = root[r1] = r2;
            rsize[r2] += rsize[r1];
        }
    }
    int find_root(int i) {
        int res = root[i];
        while (res != root[res]) {
            res = root[res];
        }
        return root[i] = res;
    }
    string smallestStringWithSwaps(
        string s, vector<vector<int>>& pairs) {

        root = vector<int>(s.size(), 0);
        rsize = vector<int>(s.size(), 1);
        int len = int(s.size()), len1 = int(pairs.size());
        for (int i = 0; i < len; i++) {
            root[i] = i;
        }
        for (int i = 0; i < len1; ++i) {
            vector<int> &t = pairs[i];
            merge(t[0], t[1]);
        }
        int pos_size = 0;
        map<int, vector<int>> poses;
        for (int i = 0; i < len; ++i) {
            int troot = find_root(i);
            poses[troot].push_back(i);
        }

        for (auto it = poses.begin(); it != poses.end(); it++) {
            vector<char> chars(it->second.size(), '0');
            vector<int> tpos(it->second.begin(), it->second.end());
            sort(tpos.begin(), tpos.end());
            for (int i = 0; i < int(tpos.size()); ++i) {
                chars[i] = s[tpos[i]];
            }
            sort(chars.begin(), chars.end());
            for (int i = 0; i < int(tpos.size()); ++i) {
                s[tpos[i]] = chars[i];
            }
        }
        return s;
    }
};
// @lc code=end

int main() {
    Solution a;
    string s = "qdwyt";
    vector<vector<int>> v {{2, 3}, {3, 2},
            {0, 1}, {4, 0}, {3, 2}};
    a.smallestStringWithSwaps(s, v);

    return 0;
}