func productExceptSelf(nums []int) []int {
	var prod int64 = 1
	zeros := 0
	for _, n := range nums {
		if n == 0 {
			zeros++
		} else {
			prod *= int64(n)
		}
	}

	ps := make([]int, len(nums))
	if zeros > 1 {
		for i := 0; i < len(ps); i++ {
			ps[i] = 0
		}
	} else if zeros == 1 {
		for i := 0; i < len(ps); i++ {
			if nums[i] != 0 {
				ps[i] = 0
			} else {
				ps[i] = int(prod)
			}
		}
	} else {
		for i := 0; i < len(ps); i++ {
			ps[i] = int(prod / int64(nums[i]))
		}
	}
	return ps
}
