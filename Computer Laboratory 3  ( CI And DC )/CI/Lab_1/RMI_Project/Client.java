import java.rmi.Naming;
import java.math.BigInteger;

public class Client {
    public static void main(String[] args) {
        try {
            Factorial obj = (Factorial) Naming.lookup("rmi://localhost/FactorialService");

            int n = 100;  
            BigInteger result = obj.fact(n);

            System.out.println("Factorial of " + n + " is:");
            System.out.println(result);

        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}