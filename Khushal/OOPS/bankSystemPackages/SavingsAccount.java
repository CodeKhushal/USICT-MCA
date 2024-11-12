package bankSystemPackages;

public class SavingsAccount extends BankAccount {
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
