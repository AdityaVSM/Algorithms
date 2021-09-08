import java.util.*;

//class itself implementing the Comparable interface
class Point implements Comparable<Point> {
    int a,b;
    public Point(int a, int b){
        this.a = a;
        this.b = b;
    }
    @Override
    public int compareTo(Point p) {
        return this.a - p.a; //For increasing order of 'a' addition for decreasing order
    }    
}
//Seperate class iplementing Comparator interface
class MyCmp implements Comparator<Point>{
    public int compare(Point p1, Point p2) {
        return p1.b - p2.b;    //increasing order of 'b'
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
        System.out.println();

        //custom class implementing comparator interface
        Arrays.sort(a, new MyCmp());
        for(Point p : a){
            System.out.print("{"+p.a+","+p.b+"} ");
        }
        System.out.println();
    }
}

//Concept is almost same for Collections.sort()