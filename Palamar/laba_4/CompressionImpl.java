import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.rmi.server.UnicastRemoteObject;

import javax.imageio.ImageIO;

import java.awt.image.BufferedImage;

public class CompressionImpl extends UnicastRemoteObject implements Compression {
    public CompressionImpl() throws java.rmi.RemoteException {

    }

    public void RLECompression(String inputFilePath, String outputFilePath) throws java.rmi.RemoteException {
        try (RandomAccessFile inputFile = new RandomAccessFile(inputFilePath, "r");
             FileOutputStream outputFile = new FileOutputStream(outputFilePath)) {
            
            byte[] header = new byte[54];
            inputFile.read(header);
            outputFile.write(header);
            
            int width = ((header[21] & 0xFF) << 24) | ((header[20] & 0xFF) << 16) | 
                        ((header[19] & 0xFF) << 8) | (header[18] & 0xFF);
            int height = ((header[25] & 0xFF) << 24) | ((header[24] & 0xFF) << 16) | 
                         ((header[23] & 0xFF) << 8) | (header[22] & 0xFF);
            int bytesPerPixel = ((header[29] & 0xFF) << 8) | (header[28] & 0xFF);
            bytesPerPixel /= 8;
            int rowSize = ((width * bytesPerPixel + 3) / 4) * 4;
            
            byte[] rowBuffer = new byte[rowSize];
            for (int row = 0; row < Math.abs(height); row++) {
                inputFile.read(rowBuffer);
                int i = 0;
                while (i < width * bytesPerPixel) {
                    int count = 1;
                    while (i + count < width * bytesPerPixel && rowBuffer[i] == rowBuffer[i + count] && count < 255) {
                        count++;
                    }
                    outputFile.write(count);
                    outputFile.write(rowBuffer[i]);
                    i += count;
                }
                outputFile.write(0);
                outputFile.write(0);
            }
            outputFile.write(0);
            outputFile.write(1);
        } catch (IOException e) {
            throw new java.rmi.RemoteException("Error processing BMP file", e);
        }
    }
    public String LZWCompression(String image) {
        return "not implements";
    }
    public String HaffmanCompression(String image) {
        return "not implements";
    }
}
