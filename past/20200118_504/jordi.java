    public String convertToBase7(int num) {
        if (num ==0) return "0";
        String result = "";
        String a = "";

        if (num < 0) {
            a = "-";
            num = -num;
        }
        while (num > 0){
            result = num%7 + result;
            num = num/7;
        }
        return a+result;
    } 
