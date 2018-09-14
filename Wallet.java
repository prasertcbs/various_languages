/**
 * Created by prasert on 3/25/2014.
 */
public class Wallet {
    private double balance, earn, spend;

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void earnMoney(double earn) {
        this.balance += earn;
    }

    public void spendMoney(double spend) {
        this.balance -= spend;
    }

    @Override
    public String toString() {
        return "Wallet{" +
                "balance=" + balance +
                '}';
    }

    public static void main(String[] args) {
        Wallet dad = new Wallet();
        dad.balance = 1000;
        System.out.println(dad.toString());
        Wallet mom;
        mom = dad;
        System.out.println(mom.toString());
        mom.spendMoney(100);
        System.out.println(dad.toString());
        System.out.println(mom.toString());
        dad.earnMoney(600);
        System.out.println(dad.toString());

        Wallet kid = new Wallet();
        kid.balance = 500;
        mom = kid;
        mom.earnMoney(200);
        System.out.println(kid.toString());
    }
}
