class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) 
      : times(move(times)) {
    int winner = 0;
    int n = persons.size();
    vector<int> votes(n, 0);
    res.reserve(n);
    for (auto& p : persons) {
      ++votes[p];
      if (votes[p] >= votes[winner])
        winner = p;
      res.push_back(winner);
    }
  }
  
  int q(int t) {
    return res[upper_bound(times.begin(), times.end(), t) - times.begin() - 1];
  }
private:
  vector<int> res;
  vector<int> times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

