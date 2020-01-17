from typing import List


class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        x_min = min(map(lambda x: x[0], rectangles))
        y_min = min(map(lambda x: x[1], rectangles))
        x_max = max(map(lambda x: x[2], rectangles))
        y_max = max(map(lambda x: x[3], rectangles))
        rectangles.sort()
        skxline = [x_min] * (y_max - y_min)
        for rect in rectangles:
            for i in range(rect[1] - y_min, rect[3] - y_min):
                if skxline[i] == rect[0]:
                    skxline[i] = rect[2]
                else:
                    return False
        return all(i == x_max for i in skxline)


if __name__ == "__main__":
    rectangles = [[0, 0, 1, 1], [0, 0, 2, 1], [1, 0, 2, 1], [0, 2, 2, 3]]
    print(Solution().isRectangleCover(rectangles))
