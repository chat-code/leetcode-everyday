#
# @lc app=leetcode id=688 lang=python3
#
# [688] Knight Probability in Chessboard
#

# @lc code=start
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        if k == 0:
            return 1.0


        def getNextStep(i, j, n):
            res = []

            res.append([i-2, j-1])
            res.append([i-2, j+1])

            res.append([i-1, j-2])
            res.append([i-1, j+2])

            res.append([i+2, j-1])
            res.append([i+2, j+1])

            res.append([i+1, j-2])
            res.append([i+1, j+2])
            
            res2 = []
            for ii in res:
                if ii[0] < 0 or ii[1] < 0 or ii[0] > (n-1) or ii[1] > (n-1):
                    continue

                res2.append(ii)    

            return res2


        rDict = {}

        for ii in range(0, n):
            for jj in range(0, n):
                v = [-1] * k
                rDict[(ii, jj)] = [getNextStep(ii, jj, n), v]


        def moveKnight(row, column, n, k, maxK, rDict):
            res = 0

            if k == maxK:
                return 1

            new_location = rDict[row, column][0]

            if rDict[row, column][1][k] != -1:
                return rDict[row, column][1][k]

            for ii in new_location:
                res += moveKnight(ii[0], ii[1], n, k+1, maxK, rDict)

            rDict[row, column][1][k] = res
            return res
        
        m = moveKnight(row, column, n, 0, k, rDict)

        return m / 8 ** k


# @lc code=end

