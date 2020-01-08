public class DinnerPlates {

    private List<int[]> stackList;
    private int stackSize;

    public DinnerPlates(int capacity) {
        stackList = new LinkedList<>();
        stackSize = capacity;
        stackList.add(new int[stackSize]);
    }

    public static void main(String[] args) {
        DinnerPlates d = new DinnerPlates(2);
        d.push(1);
        d.push(2);
        d.push(3);
        d.push(4);
        d.push(5);
        System.out.println(d.popAtStack(0));
        d.push(20);
        d.push(21);
        System.out.println(d.popAtStack(0));
        System.out.println(d.popAtStack(2));
        System.out.println(d.pop());
        System.out.println(d.pop());
        System.out.println(d.pop());
        System.out.println(d.pop());
        System.out.println(d.pop());

    }

    public void push(int val) {
        boolean added = false;
        loop:
        for (int[] stack : stackList) {
            {
                for (int i = 0; i < stack.length; i++) {
                    if (stack[i] == 0) {
                        stack[i] = val;
                        added = true;
                        break loop;
                    }
                }
            }
        }
        if (!added) {
            int[] stack = new int[stackSize];
            stack[0] = val;
            stackList.add(stack);
        }
    }

    public int pop() {
        for (int i = stackList.size() - 1; i >= 0; i--) {
            Integer temp = getInteger(i);
            if (temp != null)
                return temp;
        }
        return -1;
    }

    public int popAtStack(int index) {
        if (index >= stackList.size()) {
            return -1;
        }
        Integer temp = getInteger(index);
        if (temp != null)
            return temp;
        return -1;
    }

    private Integer getInteger(int index) {
        int[] stack = stackList.get(index);
        for (int i = stack.length - 1; i >= 0; i--) {
            if (stack[i] != 0) {
                int temp = stack[i];
                stack[i] = 0;
                return temp;
            }
        }
        return null;
    }
}