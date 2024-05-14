//给一非空的单词列表，返回前 k 个出现次数最多的单词。 
//
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。 
//
// 示例 1： 
//
// 
//输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出: ["i", "love"]
//解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//    注意，按字母顺序 "i" 在 "love" 之前。
// 
//
// 
//
// 示例 2： 
//
// 
//输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k
// = 4
//输出: ["the", "is", "sunny", "day"]
//解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//    出现次数依次为 4, 3, 2 和 1 次。
// 
//
// 
//
// 注意： 
//
// 
// 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。 
// 输入的单词均由小写字母组成。 
// 
//
// 
//
// 扩展练习： 
//
// 
// 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。 
// 
// Related Topics 堆 字典树 哈希表 
// 👍 211 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using PIS = pair<int, string>;
    struct P {
        int cnt; string s;
        bool operator>(const struct P &b) const {
            if (cnt != b.cnt) return cnt > b.cnt;
            return s < b.s;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m; for (auto &x : words) ++m[x];
        priority_queue<P, vector<P>, greater<P>> p;
        for (auto &x : m) {
            string s = x.first; int cnt = x.second; P t = P{cnt, s};
            if (p.empty()) {
               p.push(t);
            } else {
                if (p.size() < k) p.push(t);
                else
                    if (t > p.top()) { p.pop(); p.push(t); }
            }
        }
        vector<string> res;
        while (!p.empty()) { res.push_back(p.top().s); p.pop(); }
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
