import java.rmi.Naming;

public class Server {
    public static void main(String[] args) {
        try {
            FactorialImpl obj = new FactorialImpl();
            Naming.rebind("rmi://localhost/FactorialService", obj);
            System.out.println("Server ready...");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}