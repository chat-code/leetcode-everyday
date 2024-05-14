//你在进行一个简化版的吃豆人游戏。你从 [0, 0] 点开始出发，你的目的地是 target = [xtarget, ytarget] 。地图上有一些阻碍者，
//以数组 ghosts 给出，第 i 个阻碍者从 ghosts[i] = [xi, yi] 出发。所有输入均为 整数坐标 。 
//
// 每一回合，你和阻碍者们可以同时向东，西，南，北四个方向移动，每次可以移动到距离原位置 1 个单位 的新位置。当然，也可以选择 不动 。所有动作 同时 发生
//。 
//
// 如果你可以在任何阻碍者抓住你 之前 到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱
//成功。 
//
// 只有在你有可能成功逃脱时，输出 true ；否则，输出 false 。 
// 
//
// 示例 1： 
//
// 
//输入：ghosts = [[1,0],[0,3]], target = [0,1]
//输出：true
//解释：你可以直接一步到达目的地 (0,1) ，在 (1, 0) 或者 (0, 3) 位置的阻碍者都不可能抓住你。 
// 
//
// 示例 2： 
//
// 
//输入：ghosts = [[1,0]], target = [2,0]
//输出：false
//解释：你需要走到位于 (2, 0) 的目的地，但是在 (1, 0) 的阻碍者位于你和目的地之间。 
// 
//
// 示例 3： 
//
// 
//输入：ghosts = [[2,0]], target = [1,0]
//输出：false
//解释：阻碍者可以和你同时达到目的地。 
// 
//
// 示例 4： 
//
// 
//输入：ghosts = [[5,0],[-10,-2],[0,-5],[-2,-2],[-7,1]], target = [7,7]
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：ghosts = [[-1,0],[0,1],[-1,0],[0,1],[-1,0]], target = [0,0]
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= ghosts.length <= 100 
// ghosts[i].length == 2 
// -104 <= xi, yi <= 104 
// 同一位置可能有 多个阻碍者 。 
// target.length == 2 
// -104 <= xtarget, ytarget <= 104 
// 
// Related Topics 数学 
// 👍 27 👎 0


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
    bool escapeGhosts(vector <vector<int>> &ghosts, vector<int> &target) {
        int dx = abs(target[0]), dy = abs(target[1]), total = dx + dy;
        int tx = target[0], ty = target[1];
        for (auto &x : ghosts) {
            int x1 = abs(x[0] - tx), y1 = abs(x[1] - ty), total1 = x1 + y1;
            if (total1 <= total) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
