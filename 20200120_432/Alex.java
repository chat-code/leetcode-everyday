class Alex{
    HashMap<String, Node> map = new HashMap<>();
    Node head;
    Node tail;
    /**
     * Initialize your data structure here.
     */
    public AllOne() {
        head = new Node("", -1);
        tail = new Node("", -1);
        head.next = tail;
        tail.pre = head;
    }

    public static void main(String[] args) {
        AllOne allOne = new AllOne();
        allOne.inc("a");
        allOne.inc("b");
        allOne.inc("b");
        allOne.inc("c");
        allOne.inc("c");
        allOne.inc("c");
        allOne.dec("b");
        allOne.dec("b");
        System.out.println(allOne.getMinKey());
        allOne.dec("a");
        System.out.println(allOne.getMaxKey());
        System.out.println(allOne.getMinKey());
    }

    public void insertPre(Node src, Node des) {
        Node temp = des.pre;
        temp.next = src;
        src.pre = temp;
        des.pre = src;
        src.next = des;
    }

    public void insertNext(Node src, Node des) {
        Node temp = des.next;
        temp.pre = src;
        src.next = temp;
        des.next = src;
        src.pre = des;
    }

    /**
     * Inserts a new key <Key> with value 1. Or increments an existing key by 1.
     */
    public void inc(String key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value++;
            if (node.next != tail) {
                Node temp = node.next;
                while (temp != tail && temp.value < node.value) {
                    temp = temp.next;
                }
                node.pre.next = node.next;
                node.next.pre = node.pre;
                insertPre(node, temp);
            }

        } else {
            Node node = new Node(key, 1);
            map.put(key, node);
            insertNext(node, head);
        }
    }

    /**
     * Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
     */
    public void dec(String key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            if (node.value == 1) {
                node.pre.next = node.next;
                node.next.pre = node.pre;
                map.remove(key);
            } else {
                node.value--;
                if (node.pre != head) {
                    Node temp = node.pre;
                    while (temp != head && temp.value > node.value) {
                        temp = temp.pre;
                    }
                    node.pre.next = node.next;
                    node.next.pre = node.pre;
                    insertNext(node, temp);

                }

            }

        }
    }

    /**
     * Returns one of the keys with maximal value.
     */
    public String getMaxKey() {
        return tail.pre.key;
    }

    /**
     * Returns one of the keys with Minimal value.
     */
    public String getMinKey() {
        return head.next.key;
    }

    class Node {

        int value;
        String key;
        Node pre;
        Node next;

        public Node(String key, int value) {
            this.key = key;
            this.value = value;
        }
    }
}