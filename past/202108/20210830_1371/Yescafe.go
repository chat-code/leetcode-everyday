func findTheLongestSubstring(s string) int {
	var ans int
	for i := 0; i < len(s); i++ {
		cnts := map[byte]int{
			'a': 0,
			'e': 0,
			'i': 0,
			'o': 0,
			'u': 0,
		}
		if len(s)-i < ans { // optimize
			break
		}
		for j := i; j < len(s); j++ {
			if s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' {
				cnts[s[j]]++
			}
			d := j + 1 - i
			if d < ans { // optimize
				continue
			}
			if even(cnts) {
				ans = d
			}
		}
	}
	return ans
}

func even(cnts map[byte]int) bool {
	for _, v := range cnts {
		if v%2 == 1 {
			return false
		}
	}
	return true
}