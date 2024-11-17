package bankSystemPackages;

public class CurrentAccount  extends BankAccount{
    private static final double OVERDRAFT_LIMIT = 500.0;

    public CurrentAccount(String accountHolderName, double initialBalance) {
        super(accountHolderName, initialBalance);
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance + OVERDRAFT_LIMIT) {
            balance -= amount;
            System.out.println("\n\t[Withdrawn: " + amount + "]");
        } else {
            System.out.println("\n\t[Overdraft limit exceeded or invalid amount]");
        }
    }
}
