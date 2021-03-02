/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Bulb Switcher II.
Memory Usage: 5.9 MB, less than 70.21% of C++ online submissions for Bulb Switcher II.
*/

class Solution {
public:
  int flipLights(int n, int m) {
    // specified
    if (n == 0) return 0;
    if (m == 0) return 1;
    
    if (n > 3) {
      return flipLights(3, m);
    }
    
    if (n == 1) return 2;
    if (n == 2) {
      if (m == 1) return 3;
      else return 4;
    }
    // else if (n == 3) {
    if (m == 1)
      return 4;
    else if (m == 2)
      return 7;
    else
      return 8;
    // }
  }
};

// 评价：
// 不要问我或者问我自己我的代码是怎么写出来的，下面是我打的草稿，你或者是以后的我都可能不会再看得懂
/*
m = 1   4
1
2
3
4

m = 2  => 7
*commutative*
2+1 = 3 off on off
3+1 = 2 on off on

2+3 = 1 off off off

1+1 =     +1 on on on

2+4 =      +1  on off on -> off off on
3+4 =      +1  off on off -> on on off
4+1=       +1 off on on -> on off off

4 x           -1  off on on

m = 3  => 8
1+1(2+2/3+3/4+4)+1/2/3/4=1/2/3/4   4 itself +1
2+1+4=3+4
3+1+4=2+4
4+2+3=4+1
1+2+3= on on on 

m >=4  => 8
*/
// 不过我觉得应该是状态机问题
