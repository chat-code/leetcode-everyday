- [1276. 不浪费原料的汉堡制作方案](https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/)
- [1276. Number of Burgers with No Waste of Ingredients](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/)

Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

    Jumbo Burger: 4 tomato slices and 1 cheese slice.
    Small Burger: 2 Tomato slices and 1 cheese slice.

Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

 

Example 1:
```
Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese. There will be no remaining ingredients.
```

Example 2:
```
pInput: tomatoSlices = 17, cheeseSlices = 4
Output: []
Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
```

Example 3:
```
Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
```

Example 4:
```
Input: tomatoSlices = 0, cheeseSlices = 0
Output: [0,0]
```

Example 5:
```
Input: tomatoSlices = 2, cheeseSlices = 1
Output: [0,1]
```
 

Constraints:
```
    0 <= tomatoSlices <= 10^7
    0 <= cheeseSlices <= 10^7
```

-----

圣诞活动预热开始啦，汉堡店推出了全新的汉堡套餐。为了避免浪费原料，请你帮他们制定合适的制作计划。

给你两个整数 tomatoSlices 和 cheeseSlices，分别表示番茄片和奶酪片的数目。不同汉堡的原料搭配如下：

    巨无霸汉堡：4 片番茄和 1 片奶酪
    小皇堡：2 片番茄和 1 片奶酪

请你以 [total_jumbo, total_small]（[巨无霸汉堡总数，小皇堡总数]）的格式返回恰当的制作方案，使得剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量都是 0。

如果无法使剩下的番茄片 tomatoSlices 和奶酪片 cheeseSlices 的数量为 0，就请返回 []。

 

示例 1：
```
输入：tomatoSlices = 16, cheeseSlices = 7
输出：[1,6]
解释：制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 = 7 片奶酪。不会剩下原料。
```

示例 2：
```
输入：tomatoSlices = 17, cheeseSlices = 4
输出：[]
解释：只制作小皇堡和巨无霸汉堡无法用光全部原料。
```

示例 3：
```
输入：tomatoSlices = 4, cheeseSlices = 17
输出：[]
解释：制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15 片奶酪。
```

示例 4：
```
输入：tomatoSlices = 0, cheeseSlices = 0
输出：[0,0]
```

示例 5：
```
输入：tomatoSlices = 2, cheeseSlices = 1
输出：[0,1]
```
 

提示：
```
    0 <= tomatoSlices <= 10^7
    0 <= cheeseSlices <= 10^7
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
