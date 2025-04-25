package P1.P2;

public class Point3D extends Point2D {
    private double z;

    public Point3D(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    public double GetDistance() {
        return Math.sqrt(x_*x_ + y_*y_ + this.z*this.z);
    }
}
