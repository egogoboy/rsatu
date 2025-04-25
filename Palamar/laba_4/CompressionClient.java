import java.io.IOException;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class CompressionClient {
    public static void main(String args[]) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1100);
            Compression c = (Compression)Naming.lookup("rmi://localhost:1100/CompressionService");

            Boolean exit = false;
            Scanner scanner = new Scanner(System.in);
            String filePath;
            while (!exit) {
                System.out.print("Выберите опцию\n" +
                                  "1 - сжать изображение\n" +
                                  "2 - выход\n>>");
                int choise = scanner.nextInt();
                scanner.nextLine();
                
                switch (choise) {
                    case 1: {
                        try {
                            System.out.print("Введите путь до изображения: ");
                            filePath = scanner.nextLine();

                            c.RLECompression(filePath, "output.bmp");
                        } catch (IOException ex) {
                            System.out.println(ex.getMessage());
                        }
                        break;
                    }
                    case 2: {
                        exit = true;   
                        break;
                    }
                }
            }

            scanner.close();
            
        } catch (MalformedURLException murle) {
            System.out.println();
            System.out.println("MalformedURLException");
            System.out.println(murle);
        } catch (RemoteException re) { 
            System.out.println(); 
            System.out.println("RemoteException"); 
            System.out.println(re); 
		} 
		catch (NotBoundException nbe) { 
            System.out.println(); 
            System.out.println("NotBoundException"); 
            System.out.println(nbe); 
		} 
		catch (java.lang.ArithmeticException ae) { 
            System.out.println(); 
            System.out.println("java.lang.ArithmeticException"); 
            System.out.println(ae); 
		} 
    }
}
