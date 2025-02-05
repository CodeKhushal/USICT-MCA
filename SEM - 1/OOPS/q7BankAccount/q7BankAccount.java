import java.util.Scanner;

class BankAccount {
    protected String accountHolderName;
    protected int accountNumber;
    protected double balance;

    public BankAccount(String accountHolderName, double initialBalance) {
        this.accountHolderName = accountHolderName;
        this.accountNumber = 123456789;
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("\n\t[Deposited: " + amount + " to acc no. " + accountNumber + "]");
        } else {
            System.out.println("\n\t[Invalid deposit amount!]");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("\n\t[Withdrawn: " + amount + " from acc no. " + accountNumber + "]");
        } else {
            System.out.println("\n\t[Insufficient balance or invalid amount!]");
        }
    }

    public void displayBalance() {
        System.out.println("\n\t[Account Holder: " + accountHolderName + "]");
        System.out.println("\t[Current Balance: " + balance + "]");
    }
}

// Saving Account Class
class SavingsAccount extends BankAccount {
    private static final double INTEREST_RATE = 0.03; // 3% interest

    public SavingsAccount(String accountHolderName, double initialBalance) {
        super(accountHolderName, initialBalance);
    }

    public void addInterest() {
        double interest = balance * INTEREST_RATE;
        balance += interest;
        System.out.println("\n\t[Interest Added: " + interest + "]");
    }
}

// Current Account Class
class CurrentAccount extends BankAccount {
    private static final double OVERDRAFT_LIMIT = 500.0;

    public CurrentAccount(String accountHolderName, double initialBalance) {
        super(accountHolderName, initialBalance);
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance + OVERDRAFT_LIMIT) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Overdraft limit exceeded or invalid amount");
        }
    }
}

public class q7BankAccount {
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
            System.out.println(
                    "\nSaving Account Created!\n\tName: " + name + "\n\tAccount Number: " + account.accountNumber);
        } else {
            account = new CurrentAccount(name, initialBalance);
            System.out.println(
                    "\nCurrent Account Created!\n\tName: " + name + "\n\tAccount Number: " + account.accountNumber);
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
