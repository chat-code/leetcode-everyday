func maxDistToClosest(seats []int) int {
	maxx := -1
	a, b := -1, -1
	for i, v := range seats {
		if v == 1 {
			a, b = b, i
			if b-a <= 1 {
				continue
			} else {
				if a == -1 {
					maxx = Max(maxx, b)
				} else {
					maxx = Max(maxx, (b-a)/2)
				}
			}
		}
	}
	maxx = Max(maxx, len(seats)-1-b)

	return maxx
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
