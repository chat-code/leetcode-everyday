#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;

class Solution1 {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) return int(intervals.size());

    vector<PII> ps;
    for (auto &x: intervals) ps.push_back(make_pair(x[0], x[1]));
    sort(ps.begin(), ps.end());

    unordered_map<int, int> bak;
    VI far;
    far.push_back(ps[0].second);
    bak[ps[0].second] = ps[0].first;

    for (int i = 1; i < int(ps.size()); i++)
      {
        int len = int(far.size());
        auto st = lower_bound(far.begin(), far.end(), ps[i].second);
        if (st == far.end())
          {
            if (bak[far[len-1]] == ps[i].first)
                far[len-1] = ps[i].second;
            else
                far.push_back(ps[i].second);
            bak[ps[i].second] = ps[i].first;
          }
      }
    return int(far.size());
  }
};

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) return int(intervals.size());

    vector<PII> ps;
    for (auto &x: intervals) ps.push_back(make_pair(x[0], x[1]));
    sort(ps.begin(), ps.end());

    int res = 1;
    int pa = ps[0].first, pb = ps[0].second;
    for (int i = 1; i < int(ps.size()); i++)
      {
        if (ps[i].second > pb)
          {
            if (ps[i].first != pa)
              {
                pa = ps[i].first;
                res++;
              }
            pb = ps[i].second;
          }
      }

    return res;
  }
};

int main(void)
{
  Solution a;
  vector<VI> v1 {{1,4},{3,6},{2,8}};
  a.removeCoveredIntervals(v1);

  return 0;
}
