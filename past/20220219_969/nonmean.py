#
# @lc app=leetcode id=969 lang=python3
#
# [969] Pancake Sorting
#

# @lc code=start
class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        jj = len(arr) - 1
        res = []

        while jj > 0:
            ii = 0

            if arr[jj] != jj+1:
                while arr[ii] != jj+1:
                    ii += 1
                
                res.append(ii+1)
                arr[0:ii+1] = arr[0:ii+1][::-1]

                res.append(jj + 1)
                arr[0:jj+1] = arr[0:jj+1][::-1]
            
            jj -= 1

        return res

        
# @lc code=end

