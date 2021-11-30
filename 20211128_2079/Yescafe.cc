class Solution {
public:
  int wateringPlants(vector<int>& plants, int capacity) {
    int steps = plants.size();
    int used = 0;
    for (int i = 0; i < plants.size(); ++i) {
      if (capacity - used < plants[i]) {
        steps += 2 * i;
        used = 0;
      }
      used += plants[i];
    }
    return steps;
  }
};
