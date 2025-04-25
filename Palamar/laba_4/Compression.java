import java.rmi.Remote;

public interface Compression extends Remote {
    public void RLECompression(String inputFilePath, String outputFilePath) throws java.rmi.RemoteException;
    public String LZWCompression(String image) throws java.rmi.RemoteException;
    public String HaffmanCompression(String image) throws java.rmi.RemoteException;
}
