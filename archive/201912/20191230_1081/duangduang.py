class Solution:
    def smallestSubsequence(self, text: str) -> str:
        end_mark = dict()
        for idx, x in enumerate(text): end_mark[x] = idx
        ends = sorted(end_mark.values())
        visited = {}
        start = -1
        for end in ends:
            if text[end] in visited: continue
            start_mark = {}
            for i in range(start, end + 1):
                if text[i] not in visited and text[i] <= text[end]:
                    start_mark.setdefault(text[i], [])
                    start_mark[text[i]].append(i)
            for key in sorted(start_mark.keys()):
                for i in start_mark[key]:
                    if i > start:
                        start = i
                        visited[text[i]] = i
                        break
        return "".join(text[i] for i in sorted(visited.values()))


if __name__ == "__main__":
    txt = "leetcode"
    txt = "cbaacabcaaccaacababa"
    print(Solution().smallestSubsequence(txt))




        
    
