func containsPattern(arr []int, m int, k int) bool {
	for i := 0; i <= len(arr)-m*k; i++ {
		flag := true
		for j := i + m; j < i+m*k; j++ {
			if arr[j] != arr[j-m] {
				flag = false
				break
			}
		}
		if flag {
			return true
		}
	}
	return false
}
