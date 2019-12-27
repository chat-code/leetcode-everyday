public class SortCharactersByFrequency {

    public static String frequencySort(String s) {
        char[] array = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        List<Character> lst = new ArrayList<Character>();
        for (char c : array) {
            map.put(c, map.getOrDefault(c, 0) + 1);
            lst.add(c);
        }
        Map<Character, List<Character>> collect = lst.stream()
            .collect(Collectors.groupingBy(x -> x, Collectors.toList()));
        return collect.values().stream().flatMap(x -> x.stream())
            .sorted((a, b) -> map.get(b) - map.get(a)).map(x -> x + "")
            .collect(Collectors.joining());
    }
}