public class functionTable {
private double x;
private double x2;
private double x3;
private double xsqrt2;
private double xsqrt4;
  public functionTable(int x) {
  this.x = x;
  this.x2 = Math.pow(x,2);
  this.x3 = Math.pow(x,3);
  this.xsqrt2 = Math.pow(x, 1.0/2.0);
  this.xsqrt4 = Math.pow(x, 1.0/4.0);
  }
public String toString () {
  return (" " + x + "     " + x2 + "   " + xsqrt2 + "  " + x3 + "   "  + xsqrt4);
}
/*
public String toStringdos () {
  String s = (" %d  %0.3f    %f   %f %f" , x ,  x2 , xsqrt2, x3, xsqrt4);
return s;}
'*/
}
class Main {
  public static void main(String[] args) {
  functionTable f; 
  int x = 2;

    System.out.println("Number  Square  Square Rooot  Cube  4th Root");
    for (x = 1; x < 21; x++)
    {
    f = new functionTable(x);
    System.out.println(f.toString());
    }

  }
}
