package P1.P2;

import java.util.Scanner;

public class Points {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Введите x и y для первой точки: ");
            double x, y;
            x = scanner.nextDouble();
            y = scanner.nextDouble();
            Point2D point2 = new Point2D(x, y);
            System.out.print("Введите x, y и z для второй точки: ");
            double z;
            x = scanner.nextDouble();
            y = scanner.nextDouble();
            z = scanner.nextDouble();
            Point3D point3 = new Point3D(x, y, z);

            System.out.println("Расстояние от первой точки до начала координат: " + point2.GetDistance());
            System.out.println("Расстояние от второй точки до начала координат: " + point3.GetDistance());
        }
    }
}
