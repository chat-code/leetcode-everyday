import (
	"sort"
)

type Trie struct {
	m map[rune]*Trie
}

func ConstructTrie(products []string) (trie Trie) {
	trie.m = make(map[rune]*Trie)
	for _, prod := range products {
		curr := &trie
		for _, ru := range prod {
			if val, ok := curr.m[ru]; ok {
				curr = val
			} else {
				curr.m[ru] = &Trie{make(map[rune]*Trie)}
				curr = curr.m[ru]
			}
		}
		curr.m['_'] = nil
	}
	return trie
}

func (this *Trie) Move(c rune) *Trie {
	if this == nil {
		return nil
	}
	return this.m[c]
}

func three(ret *[]string, t *Trie, prefix string) {
	if t == nil {
		return
	}

	for k, v := range t.m {
		if k == '_' {
			*ret = append(*ret, prefix)
		}
		three(ret, v, prefix+string(k))
	}
}

func (this *Trie) Three(prefix string) []string {
	var ret []string
	three(&ret, this, prefix)
	sort.Strings(ret)
	if len(ret) >= 3 {
		return ret[:3]
	} else {
		return ret
	}
}

func suggestedProducts(products []string, searchWord string) (o [][]string) {
	trie := ConstructTrie(products)
	t := &trie
	prefix := ""
	for _, ru := range searchWord {
		prefix += string(ru)
		t = t.Move(ru)
		o = append(o, t.Three(prefix))
	}
	return
}