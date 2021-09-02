import "strconv"
import "strings"

func compareVersion(version1 string, version2 string) int {
	v1, v2 := strings.Split(version1, "."), strings.Split(version2, ".")
	l, l1, l2 := 0, len(v1), len(v2)
	if l1 > l2 {
		l = l1
	} else {
		l = l2
	}
	for i := 0; i < l; i++ {
		var n1, n2 int64 = 0, 0
		if i < l1 {
			n1, _ = strconv.ParseInt(v1[i], 10, 32)
		}
		if i < l2 {
			n2, _ = strconv.ParseInt(v2[i], 10, 32)
		}

		if n1 < n2 {
			return -1
		} else if n1 > n2 {
			return 1
		}
	}
	return 0
}