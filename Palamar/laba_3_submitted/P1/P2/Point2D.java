package P1.P2;

public class Point2D {
    protected double x_;
    protected double y_;

    public Point2D(double x, double y) {
        x_ = x;
        y_ = y;
    }

    public double GetDistance() {
        return Math.sqrt(x_*x_ + y_*y_);
    }
}
