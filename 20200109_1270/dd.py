import bisect
from typing import List


class DinnerPlates:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stacks: List[List[int]] = [[]]
        self.not_full = [0]
        self.not_empties = []

    def __repr__(self):
        return f"not_full: {self.not_full}, not_empties: {self.not_empties} \nstacks: {self.stacks}"

    def push(self, val: int) -> None:
        avail = self.stacks[self.not_full[0]]
        if len(avail) == 0:
            bisect.insort_left(self.not_empties, self.not_full[0])
        avail.append(val)
        if len(avail) >= self.capacity:
            self.not_full.pop(0)
            if len(self.not_full) == 0:
                self.not_full.append(len(self.stacks))
                self.stacks.append([])

    def pop(self) -> int:
        if len(self.not_empties) == 0:
            return -1
        else:
            not_empty = self.stacks[self.not_empties[-1]]
            if len(not_empty) == self.capacity:
                bisect.insort_left(self.not_full, self.not_empties[0])
            r = not_empty.pop()
            if len(not_empty) == 0:
                self.not_empties.pop()
            return r

    def popAtStack(self, index: int) -> int:
        if index > len(self.stacks) or not self.stacks[index]:
            return -1
        sk = self.stacks[index]
        if len(sk) == self.capacity:
            bisect.insort_left(self.not_full, index)
        r = sk.pop()
        if len(sk) == 0:
            del self.not_empties[bisect.bisect_left(self.not_empties, index)]
        return r


def eval(ops, paras):
    dp = DinnerPlates(*paras[0])
    for op, para in zip(ops[1:], paras[1:]):
        print(dp)
        print(f"{op}({para})", {
            "push": dp.push,
            "popAtStack": dp.popAtStack,
            "pop": dp.pop
        }[op](*para))
        print("-----------")


if __name__ == "__main__":
    d_ops = ["DinnerPlates", "push", "push", "push", "push", "push", "push", "push", "popAtStack", "popAtStack",
             "popAtStack",
             "popAtStack", "popAtStack", "push", "push", "pop", "pop", "pop", "pop", "pop"]
    d_paras = [[2], [1], [2], [3], [4], [5], [6], [7], [2], [2], [1], [1], [0], [8], [9], [], [], [], [], []]
    eval(d_ops, d_paras)
    # Your DinnerPlates object will be instantiated and called as such:
    # obj = DinnerPlates(capacity)
    # obj.push(val)
    # param_2 = obj.pop()
    # param_3 = obj.popAtStack(index)
    # D = DinnerPlates(2)  # Initialize with capacity = 2
    # D.push(1)
    # D.push(2)
    # D.push(3)
    # D.push(4)
    # D.push(5)
    # print(D)
    # D.pop()
    # print(D)
