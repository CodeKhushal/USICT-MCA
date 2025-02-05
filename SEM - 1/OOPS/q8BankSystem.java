import java.util.Scanner;
import bankSystemPackages.BankAccount;
import bankSystemPackages.SavingsAccount;
import bankSystemPackages.CurrentAccount;

public class q8BankSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter account holder's name: ");
        String name = scanner.nextLine();

        System.out.print("Enter initial balance: ");
        double initialBalance = scanner.nextDouble();

        System.out.print("Choose account type (1 for Savings, 2 for Current): ");
        int accountType = scanner.nextInt();

        BankAccount account;
        if (accountType == 1) {
            account = new SavingsAccount(name, initialBalance);
            System.out.println("\tSaving Account Created!");
        } else {
            account = new CurrentAccount(name, initialBalance);
            System.out.println("\tCurrent Account Created!");
        }

        boolean exit = false;
        while (!exit) {
            System.out.println("\nChoose an operation:");
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Display Balance");
            if (account instanceof SavingsAccount) {
                System.out.println("4. Add Interest");
            }
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    if (account instanceof SavingsAccount) {
                        ((SavingsAccount) account).addInterest();
                    } else {
                        System.out.println("Invalid choice for current account.");
                    }
                    break;
                case 5:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }

        scanner.close();
    }
}