//假设 力扣（LeetCode）即将开始其 IPO。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。 由于资源有限
//，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。 
//
// 给定若干个项目。对于每个项目 i，它都有一个纯利润 Pi，并且需要最小的资本 Ci 来启动相应的项目。最初，你有 W 资本。当你完成一个项目时，你将获得纯
//利润，且利润将被添加到你的总资本中。 
//
// 总而言之，从给定项目中选择最多 k 个不同项目的列表，以最大化最终资本，并输出最终可获得的最多资本。 
//
// 
//
// 示例： 
//
// 
//输入：k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
//输出：4
//解释：
//由于你的初始资本为 0，你仅可以从 0 号项目开始。
//在完成后，你将获得 1 的利润，你的总资本将变为 1。
//此时你可以选择开始 1 号或 2 号项目。
//由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
//因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
// 
//
// 
//
// 提示： 
//
// 
// 假设所有输入数字都是非负整数。 
// 表示利润和资本的数组的长度不超过 50000。 
// 答案保证在 32 位有符号整数范围内。 
// 
// Related Topics 堆 贪心算法 
// 👍 74 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using VI = vector<int>;
    using PII = pair<int, int>;
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<PII> v;
        int n = Profits.size();
        for (int i = 0; i < n; ++i) v.push_back(PII(Profits[i], Capital[i]));
        sort(v.begin(), v.end(), [](const PII& a, const PII& b) { return a.second < b.second; });
        int res {W};
        priority_queue<int, VI, less<int>> p;
        int idx {};
        while (k--) {
            for (int i = idx; i < n; ++i) {
                if (v[i].second <= res) { ++idx; p.push(v[i].first); }
            }
            if (p.empty()) break;
            res += p.top(); p.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
