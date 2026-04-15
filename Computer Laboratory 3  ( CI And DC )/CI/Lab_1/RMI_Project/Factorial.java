import java.rmi.Remote;
import java.rmi.RemoteException;
import java.math.BigInteger;

public interface Factorial extends Remote {
    BigInteger fact(int n) throws RemoteException;
}