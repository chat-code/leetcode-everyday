#
# @lc app=leetcode id=661 lang=python3
#
# [661] Image Smoother
#

# @lc code=start
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        r = []

        r.append([-1] * (n + 2))

        for ii in range(0, m):
            r.append([])

            r[-1].append(-1)

            for jj in range(0, n):
                r[-1].append(img[ii][jj])
            
            r[-1].append(-1)

        r.append([-1] * (n + 2))

        for ii in range(1, m + 1):
            for jj in range(1, n + 1):
                c = 0
                count = 0

                for p in [-1, 0, 1]:
                    for q in [-1, 0, 1]:
                        if r[ii+p][jj+q] >= 0:
                            c += r[ii+p][jj+q]
                            count += 1
                        
                img[ii-1][jj-1] = c // count

        return img

        
# @lc code=end

