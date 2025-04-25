import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CompressionServer {
    public CompressionServer() {
        try {
            Compression c = new CompressionImpl();
            Naming.rebind("rmi://localhost:1100/CompressionService", c);
        } catch (Exception e) {
            System.out.println("Trouble: " + e);
        }

    }
    public static void main(String args[]) throws java.rmi.RemoteException {
        System.out.println("Создание rmi-регистра\n");
        final Registry registry = LocateRegistry.createRegistry(1100);
        System.out.println("Rmi-регистр создан!\n");
        new CompressionServer();
    }
}
