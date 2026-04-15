import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.math.BigInteger;

public class FactorialImpl extends UnicastRemoteObject implements Factorial {

    protected FactorialImpl() throws RemoteException {
        super();
    }

    public BigInteger fact(int n) {
        BigInteger result = BigInteger.ONE;
        for(int i = 1; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
}