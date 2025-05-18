public class q11ValidateNumber {
    public static void checkValidNumber(String[] arr) {
        for (String str : arr) {
            System.out.println();
            try {
                Integer.parseInt(str);
                System.out.println(str + " is a valid integer.");
            } catch (NumberFormatException e1) {
                try {
                    Double.parseDouble(str);
                    System.out.println(str + " is a valid double.");
                } catch (NumberFormatException e2) {
                    System.out.println(str + " is not a valid integer or double.");
                }
            }
        }
    }
    public static void main(String[] args) {
        String[] arr = { "100", "10.2", "5.hello", "100hello" };
        checkValidNumber(arr);
    }
}
