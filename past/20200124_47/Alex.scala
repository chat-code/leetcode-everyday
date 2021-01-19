object alex {
  def permuteUnique(nums: Array[Int]): List[List[Int]] = {
    import scala.collection.mutable
    var res: mutable.Stack[List[Int]] = mutable.Stack()
    var t: mutable.Stack[Int] = mutable.Stack()
    val used = Array.ofDim[Boolean](nums.length)

    def dfs(candidates: Array[Int], s: Int, temp: mutable.Stack[Int], res: mutable.Stack[List[Int]], used: Array[Boolean]): Unit = {
      if (temp.length == candidates.length) {
        res push temp.toList
        return
      }
      var i = 0
      while (i < candidates.length) {
        if (used(i) || i > 0 && candidates(i) == candidates(i - 1) && !used(i - 1)) {
        } else {
          used(i) = true
          temp.push(candidates(i))
          dfs(candidates, i, temp, res, used)
          used(i) = false
          temp.pop()
        }
        i += 1
      }
    }

    val tt = nums.sorted
    dfs(tt, 0, t, res, used)
    res.toList
  }
}