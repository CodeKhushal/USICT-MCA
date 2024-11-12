package bankSystemPackages;

public class BankAccount {
    protected String accountHolderName;
    protected int accountNumber;
    protected double balance;

    public BankAccount(String accountHolderName, double initialBalance) {
        this.accountHolderName = accountHolderName;
        this.accountNumber = 123456789;
        this.balance = initialBalance;
        System.out.println("\n\tName: " + accountHolderName + "\n\tAccount Number: " + accountNumber);
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
