import java.util.*;

class Point implements Comparable<Point> {
    int a,b;
    public Point(int a, int b){
        this.a = a;
        this.b = b;
    }
    @Override
    public int compareTo(Point p) {
        return this.a - p.a; //For increasing order addition for decreasing order
    }    
}
public class Main{
    public static void main(String[] args){
        Point a[] = {new Point(10,20), new Point(3,12), new Point(5,7)};
        //Increasing order
        Arrays.sort(a);
        for(Point p : a){
            System.out.print("{"+p.a+","+p.b+"} ");
        }

        System.out.println();
        //Decreasing order
        Arrays.sort(a,Collections.reverseOrder());
        for(Point p : a){
            System.out.print("{"+p.a+","+p.b+"} ");
        }

    }
}