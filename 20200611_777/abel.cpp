//在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。一次移动操作指用一个"LX"替换一个"XL"，或
//者用一个"XR"替换一个"RX"。现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回T
//rue。 
//
// 
//
// 示例 : 
//
// 输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
//输出: True
//解释:
//我们可以通过以下几步将start转换成end:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
// 
//
// 
//
// 提示： 
//
// 
// 1 <= len(start) = len(end) <= 10000。 
// start和end中的字符串仅限于'L', 'R'和'X'。 
// 
// Related Topics 脑筋急转弯 
// 👍 82 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

const int N = 10009;
char a[N], b[N];
int ai[N], bi[N];

class Solution {
public:
    bool canTransform(string start, string end) {
        int alen = 0, blen = 0;
        if (start.size() != end.size()) return false;

        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(ai, 0, sizeof ai);
        memset(bi, 0, sizeof bi);

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L' || start[i] == 'R') {
                a[alen] = start[i];
                ai[alen] = i;
                ++alen;
            }
            if (end[i] == 'L' || end[i] == 'R') {
                b[blen] = end[i];
                bi[blen] = i;
                ++blen;
            }
        }
        if (alen != blen) return false;
        for (int i = 0; i < alen; ++i) {
            if (a[i] != b[i]) return false;
            if (a[i] == 'L') {
                if (bi[i] > ai[i]) return false;
            } else {
                if (bi[i] < ai[i]) return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
