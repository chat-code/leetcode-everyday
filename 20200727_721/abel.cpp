//给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其
//余元素是 emails 表示该账户的邮箱地址。 
//
// 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为
//人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。 
//
// 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnn
//ybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Ma
//ry", "mary@mail.com"]]
//输出：
//[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
//["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//解释：
//第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
//第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
//可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
//['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的
//。
// 
//
// 
//
// 提示： 
//
// 
// accounts的长度将在[1，1000]的范围内。 
// accounts[i]的长度将在[1，10]的范围内。 
// accounts[i][j]的长度将在[1，30]的范围内。 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 149 👎 0


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
    map<string, int> nm;
    map<int, VS> emails;

    vector <vector<string>> accountsMerge(vector <vector<string>> &accounts) {
        for (int i = 0; i < accounts.size(); i++) {
            if (i == 0) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    nm[accounts[i][j]] = i;
                    emails[i].push_back(accounts[i][j]);
                }
            } else {
                int idx = -1;
                for (int j = 1; j < accounts[i].size(); j++) {
                    if (nm.find(accounts[i][j]) != nm.end()) {
                        idx = nm[accounts[i][j]];
                        break;
                    }
                }
                if (idx == -1) idx = i;
                for (int j = 1; j < accounts[i].size(); j++) {
                    if (nm.find(accounts[i][j]) == nm.end()) {
                        nm[accounts[i][j]] = idx;
                        emails[idx].push_back(accounts[i][j]);
                    } else {
                        int pidx = nm[accounts[i][j]];
                        if (pidx != idx) {
                            for (auto &x: emails[pidx]) {
                                nm[x] = idx;
                                emails[idx].push_back(x);
                            }
                            emails.erase(pidx);
                        }
                    }
                }
            }
        }
        vector <VS> res;
        for (auto &x : emails) {
            VS tmp;
            tmp.push_back(accounts[x.first][0]);

            set <string> ss;
            for (auto &y : x.second) {
                ss.insert(y);
            }
            for (auto &y: ss) {
                tmp.push_back(y);
            }
            sort(tmp.begin() + 1, tmp.end());

            res.push_back(tmp);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
