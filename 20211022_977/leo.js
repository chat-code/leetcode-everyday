/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    if (!nums) return;

    for (let i = 0; i < nums.length; i++) {
        nums[i] *= nums[i];
    }

    return nums.sort((a, b) => a - b)
};