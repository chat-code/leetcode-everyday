func rangeBitwiseAnd(left int, right int) int {
  cnt := 0
  for left < right {
    left >>= 1
    right >>= 1
    cnt++
  }
  return left << cnt
}
