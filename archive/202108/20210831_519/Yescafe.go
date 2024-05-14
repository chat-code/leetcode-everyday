import "math/rand"

type Solution struct {
	used map[int]bool
	rows int
	cols int
}

func Constructor(m int, n int) Solution {
	return Solution{
		used: make(map[int]bool),
		rows: m,
		cols: n,
	}
}

func (this *Solution) Flip() []int {
	mod := this.rows * this.cols
	v := rand.Int() % mod
	for _, ok := this.used[v]; ok; _, ok = this.used[v] {
		v = (v + 1) % mod
	}
	this.used[v] = true
	return []int{v / this.cols, v % this.cols}
}

func (this *Solution) Reset() {
	this.used = make(map[int]bool)
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(m, n);
 * param_1 := obj.Flip();
 * obj.Reset();
 */
