//每封电子邮件都由一个本地名称和一个域名组成，以 @ 符号分隔。 
//
// 例如，在 alice@leetcode.com中， alice 是本地名称，而 leetcode.com 是域名。 
//
// 除了小写字母，这些电子邮件还可能包含 '.' 或 '+'。 
//
// 如果在电子邮件地址的本地名称部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名称中没有点的同一地址。例如，"alice.z@leet
//code.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。 （请注意，此规则不适用于域名。） 
//
// 如果在本地名称中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件，例如 m.y+name@email.com 将转发到 my@
//email.com。 （同样，此规则不适用于域名。） 
//
// 可以同时使用这两个规则。 
//
// 给定电子邮件列表 emails，我们会向列表中的每个地址发送一封电子邮件。实际收到邮件的不同地址有多少？ 
//
// 
//
// 示例： 
//
// 输入：["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","test
//email+david@lee.tcode.com"]
//输出：2
//解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= emails[i].length <= 100 
// 1 <= emails.length <= 100 
// 每封 emails[i] 都包含有且仅有一个 '@' 字符。 
// 
// Related Topics 字符串 
// 👍 144 👎 0


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
    string normal(string s) {
        size_t pos = s.find("@");
        string post = s.substr(pos);
        string prefix = s.substr(0, pos);
        string nprefix;
        for (int i = 0; i < prefix.size(); ++i) {
            if (prefix[i] == '+') break;
            else if (prefix[i] == '.') continue;
            else nprefix = nprefix + prefix[i];
        }
        return nprefix + post;
    }

    int numUniqueEmails(vector <string> &emails) {
        int len = emails.size();
        set <string> ns;
        for (int i = 0; i < len; ++i) {
            ns.insert(normal(emails[i]));
        }
        return ns.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
