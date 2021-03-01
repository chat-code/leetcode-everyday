class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        return getDevisorsVector(num) == num;
    }
    int getDevisorsVector(int num) {
        int res = 1;
        // 找到一个因子，就可以用 num / i 找到另一个因子，可以少循环几次
        for (int i = 2; i < sqrt(num); i++) {
            if (num % i == 0) {
                res += i;
                res += num / i;
            }
        }
        return res;
    }
};