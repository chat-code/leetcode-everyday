package main

import (
	"fmt"
)

func lengthOfLongestSubstring(s string) int {
	type empty struct{}
	chars := make(map[byte]empty, 26)
	pos := make(map[byte]int, 26)
	res, a := 0, 0

	for i := 0; i < len(s); i++ {
		v := s[i]
		if _, ok := chars[v]; ok {
			_pos := pos[v]
			for j := a; j < _pos; j++ {
				delete(chars, s[j])
			}
			a = _pos + 1
			pos[v] = i
		} else {
			chars[v] = empty{}
			pos[v] = i
			_len := i - a + 1
			if _len > res {
				res = _len
			}
		}
	}

	return res
}

func main() {
	fmt.Println("Hello world")
	fmt.Println(lengthOfLongestSubstring("abcabc"))
	fmt.Println(lengthOfLongestSubstring("abcabca"))
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
	fmt.Println(lengthOfLongestSubstring("bbbbb"))
	fmt.Println(lengthOfLongestSubstring("pwwkew"))
}
