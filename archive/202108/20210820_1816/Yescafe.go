import "strings"

func truncateSentence(s string, k int) string {
	return strings.Join(strings.Split(s, " ")[:k], " ")
}