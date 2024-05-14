#
# @lc app=leetcode id=1994 lang=python3
#
# [1994] The Number of Good Subsets
#

# @lc code=start
class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        rDict = {1:[1], 2:[2], 3:[3], 5:[5], 6:[2, 3], 
                 7:[7], 10:[2, 5], 11:[11], 13:[13], 
                 14:[2,7], 15:[3,5], 17:[17], 19:[19], 
                 21:[3,7], 22:[2,11], 23:[23], 26:[2,13], 
                 29:[29], 30:[2,3,5]}

        rDict3 = {}

        for ii in nums:
            if ii in rDict.keys(): 
                rDict3[ii] = rDict3.get(ii, 0) + 1

        n1 = rDict3.pop(1, 0)

        def searchSubsets(rDict, rDict3, r, i, c, n):
            res = 0

            for ii in range(i, len(c)):
                flag = True
                for jj in rDict[c[ii]]:
                    if r[jj] >= 1:
                        flag = False
                    r[jj] += 1

                if flag == True:
                    res += n * rDict3[c[ii]] + searchSubsets(rDict, rDict3, r, ii+1, c, n * rDict3[c[ii]])

                for jj in rDict[c[ii]]:
                    r[jj] -= 1
            
            return res

        r = [0] * 30 # max primary number + 1

        res = searchSubsets(rDict, rDict3, r, 0, list(rDict3.keys()), 1)

        return ((res * (2 ** (n1))) % (1000000000 + 7))

        
# @lc code=end

