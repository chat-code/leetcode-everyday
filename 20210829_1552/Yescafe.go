import "sort"

func maxDistance(position []int, m int) (ret int) {
    n := len(position)
    sort.Ints(position)
    
    l, r := 1, position[n-1] - position[0]
    for l <= r {
        mid := (l + r) / 2
        if valid(position, m, mid) {
            ret = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return
}

func valid(position []int, m int, dis int) bool {
    n := len(position)
    p := position[0]
    m--
    for i := 0; i < n; i++ {
        if position[i] - p >= dis {
            p = position[i]
            m--
        }
    }
    
    return m <= 0
}