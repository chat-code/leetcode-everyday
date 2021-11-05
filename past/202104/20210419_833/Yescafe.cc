/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// Your runtime beats 81.15 % of cpp submissions
// Your memory usage beats 48.46 % of cpp submissions (10.8 MB)

#include <algorithm>
#include <tuple>

class Solution {
public:
  string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    vector<tuple<int, string, string>> tvec;
    for (int i = 0; i < indexes.size(); ++i) {
      tvec.emplace_back(indexes[i], sources[i], targets[i]);
    }
    std::sort(tvec.begin(), tvec.end(), [](const auto& t1, const auto& t2) {
      return get<0>(t1) < get<0>(t2);
    });

    string output {s};
    int ii = 0;
    int bias = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (ii < tvec.size() && i == get<0>(tvec[ii])) {
        if (s.substr(get<0>(tvec[ii]), get<1>(tvec[ii]).length()) == get<1>(tvec[ii])) {
          output.replace(get<0>(tvec[ii]) + bias, get<1>(tvec[ii]).length(), get<2>(tvec[ii]));
          bias += get<2>(tvec[ii]).length() - get<1>(tvec[ii]).length();
          i += get<1>(tvec[ii]).length() - 1;
        }
        ++ii;
      }
    }

    return output;
  }
};
// @lc code=end

// "abcd"\n[0, 2]\n["ab","ec"]\n["eee","ffff"]
// "vmokgggqzp"\n[3,5,1]\n["kg","ggq","mo"]\n["s","so","bfr"]

int main() {
  string a {"vmokgggqzp"};
  vector<int> b {3, 5, 1};
  vector<string> c {"kg","ggq","mo"};
  vector<string> d {"s","so","bfr"};
  cout << Solution().findReplaceString(a, b, c, d) << endl;
}