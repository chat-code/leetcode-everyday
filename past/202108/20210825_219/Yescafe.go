func containsNearbyDuplicate(nums []int, k int) bool {
	dict := make(map[int]int)
	minn := len(nums) + 1
	for i, n := range nums {
		if p, ok := dict[n]; ok {
			minn = Min(minn, i-p)
		}
		dict[n] = i
	}
	return minn != len(nums)+1 && minn <= k
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
