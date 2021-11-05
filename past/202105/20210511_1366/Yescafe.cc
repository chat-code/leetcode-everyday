// Runtime: 20 ms, faster than 29.96% of C++ online submissions for Rank Teams by Votes.
// Memory Usage: 10.6 MB, less than 84.48% of C++ online submissions for Rank Teams by Votes.

class Solution {
public:
  string rankTeams(vector<string>& votes) {
    map<char, vector<int>> weights;
    auto len = votes[0].length();
    for (int i = 0; i < votes.size(); ++i) {
      for (int ii = 0; ii < len; ++ii) {
        if (i == 0)
          weights.insert(make_pair(votes[i][ii], vector<int>(len, 0)));
        ++weights[votes[i][ii]][ii];
      }
    }
    
    string str;
    std::transform(weights.begin(), weights.end(), back_inserter(str), [](const auto& a) {
      return a.first;
    });
    std::sort(str.begin(), str.end(), [&](const auto& a, const auto& b) {
      auto& pa = weights[a];
      auto& pb = weights[b];
      for (int i = 0; i < pa.size(); ++i) {
        if (pa[i] != pb[i]) {
          return pa[i] > pb[i];
        }
      }
      return a < b;
    });
    return str;
  }
};

