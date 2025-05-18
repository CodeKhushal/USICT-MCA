import java.util.Scanner;

public class q6ReverseInteger {
    public static int reverse(Integer number) {
        Integer temp = number;
        Integer res = 0;
        while (temp > 0) {
            res = res * 10 + temp % 10;
            temp = temp / 10;
        }
        return res;
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int choice = 0, num;
        do {
            System.out.print("1. Reverse a number\n2. Exit\n\nChoice: ");
            choice = scanner.nextInt();
            if (choice == 2)
                break;
            System.out.print("Enter the number:");
            num = scanner.nextInt();
            Integer reversedNumber = reverse(num);
            System.out.println("\n\t[Original: " + num + ", Reversed: " + reversedNumber + "]\n");
        } while (choice != 2);
        scanner.close();
    }
}