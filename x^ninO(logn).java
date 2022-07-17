import java.util.*;
public class Main{
public static int powr(int x, int n)
{
  if(n==0) return 1; 
  if(n%2==0)  return x*powr(x,n/2) ;
  return x*x*powr(x,n/2) ;
}
public static void main(String args[]){
   
   System.out.println("2^ 5 is "+ powr(2,5)); ;
  }
}