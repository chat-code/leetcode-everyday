type RecentCounter struct {
    set map[int]bool
}


func Constructor() RecentCounter {
    return RecentCounter{make(map[int]bool)}
}


func (this *RecentCounter) Ping(t int) (cnt int) {
    this.set[t] = true
    cnt = 0
    for i := t - 3000; i <= t; i++ {
        if _, v := this.set[i]; v {
            cnt++
        }
    }
    return
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */

