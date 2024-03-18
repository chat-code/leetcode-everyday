#
# @lc app=leetcode id=1001 lang=python3
#
# [1001] Grid Illumination
#

# @lc code=start
class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        h = {}
        v = {}
        d1 = {}
        d2 = {}
        l ={}

        for ii in lamps:
            if ii[0] in h.keys():
                h[ii[0]] += 1
            else:
                h[ii[0]] = 1

            if ii[1] in v.keys():
                v[ii[1]] += 1
            else:
                v[ii[1]] = 1

            if ii[0] - ii[1] in d1.keys():
                d1[ii[0] - ii[1]] += 1
            else:
                d1[ii[0] - ii[1]] = 1
            
            if (n - 1 - ii[0]) - ii[1] in d2.keys():
                d2[(n - 1 - ii[0]) - ii[1]] += 1
            else:
                d2[(n - 1 - ii[0]) - ii[1]] = 1

            if tuple(ii) in l.keys():
                l[tuple(ii)] += 1
            else:
                l[tuple(ii)] = 1

        def turnOff(ii, l, h, v, d1, d2, n):
            if tuple(ii) in l.keys() and l[tuple(ii)] > 0:
                print("remove", ii)
                h[ii[0]] -= l[tuple(ii)]
                v[ii[1]] -= l[tuple(ii)]
                d1[ii[0] - ii[1]] -= l[tuple(ii)]
                d2[(n - 1 - ii[0]) - ii[1]] -= l[tuple(ii)]

                l[tuple(ii)] = 0


        res = []
        for ii in queries:
            if (ii[0] in h.keys() and h[ii[0]] > 0)      \
                    or (ii[1] in v.keys() and v[ii[1]] > 0)  \
                    or ((ii[0] - ii[1]) in d1.keys() and d1[ii[0] - ii[1]] > 0) \
                    or (((n - 1 - ii[0]) - ii[1]) in d2.keys() and d2[(n - 1 - ii[0]) - ii[1]] > 0):
                
                res.append(1)
            else:
                res.append(0)

            if res[-1] == 1:
                for p in range(ii[0]-1, ii[0]+2):
                    for q in range(ii[1]-1, ii[1]+2):
                        turnOff([p, q], l, h, v, d1, d2, n)

        return res
            
        
# @lc code=end

