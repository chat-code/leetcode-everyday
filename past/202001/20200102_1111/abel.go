package main

import "fmt"

func maxDepthAfterSplit(seq string) []int {
	res := make([]int, 0, len(seq))
	stack := make([]int, 0, len(seq))
	for i := 0; i < len(seq); i++ {
		if seq[i] == '(' {
			r := len(stack) % 2
			res = append(res, r)
			stack = append(stack, r)
		} else {
			l := len(stack) - 1
			res = append(res, stack[l])
			stack = stack[:l]
		}
	}

	return res
}

func main() {
	fmt.Println(maxDepthAfterSplit("(()())"))
	fmt.Println(maxDepthAfterSplit("()(())()"))
}
