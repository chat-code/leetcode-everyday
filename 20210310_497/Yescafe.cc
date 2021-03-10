/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

#include <iostream>
#include <vector>
using std::vector;

// @lc code=start
// Runtime: 192 ms, faster than 15.33% of C++ online submissions for Random Point in Non-overlapping Rectangles.
// Memory Usage: 67.2 MB, less than 83.94% of C++ online submissions for Random Point in Non-overlapping Rectangles.

#include <random>

class Solution {
public:
  Solution(vector<vector<int>>& rects) {
    this->rects = rects;
    areas.reserve(rects.size());
    total_area = 0;
    for (auto&& ps : rects) {
      auto area = cal_area(ps);
      areas.push_back(area);
      total_area += area;
    }
  }
    
  vector<int> pick() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(0, total_area - 1);
    auto rand = distrib(gen);

    int area_sum = 0;
    int idx, relative_pos;
    for (idx = 0; idx < areas.size(); ++idx) {
      if (area_sum + areas[idx] > rand) {
        relative_pos = rand - area_sum;
        break;
      }
      area_sum += areas[idx];
    }

    return {
      rects[idx][0] + relative_pos / (rects[idx][3] - rects[idx][1] + 1),
      rects[idx][1] + relative_pos % (rects[idx][3] - rects[idx][1] + 1)
    };
  }

private:
  static int cal_area(std::vector<int>& ps) {
    return (ps[2] - ps[0] + 1) * (ps[3] - ps[1] + 1);
  }

private:
  std::vector<std::vector<int>> rects;
  std::vector<int> areas;
  int total_area;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

// 评价：
// 这是我从出生以来见过最魔幻的题目。
